#include <stdio.h>
#include <stdlib.h>

#include "matrix.h"

struct _matrix {
  int rows, cols;
  double * data;
};

double getE(matrix const * mtx, int row, int col) {
  return mtx->data[(col-1) * mtx->rows + row - 1];
}

void setE(matrix * mtx, int row, int col, double val) {
  mtx->data[(col-1) * mtx->rows + row - 1] = val;
}

int badArgs(matrix const * mtx, int row, int col) {
  if (!mtx || !mtx->data)
    return -1;
  if (row <= 0 || row > mtx->rows ||
      col <= 0 || col > mtx->cols)
    return -2;
  return 0;
}

matrix * newMatrix(int rows, int cols) {
  int i;
  matrix * m;
  if (rows <=0 || cols <= 0) return NULL;

  /* allocate a matrix structure */
  m = malloc(sizeof(matrix));
  if (!m) return NULL;

  /* set dimensions */
  m->rows = rows;
  m->cols = cols;

  /* allocate a double array of length rows * cols */
  m->data = malloc(rows*cols*sizeof(double));
  if (!m->data) {
    free(m);
    return NULL;
  }
  /* set all data to 0 */
  for (i = 0; i < rows*cols; i++)
    m->data[i] = 0.0;

  return m;
}

void deleteMatrix(matrix * mtx) {
  if (mtx) {
    /* free mtx's data */
    free(mtx->data);
    /* free mtx itself */
    free(mtx);
  }
}

int setElement(matrix * mtx, int row, int col,
               double val) {
  int err = badArgs(mtx, row, col);
  if (err) return err;
  setE(mtx, row, col, val);
  return 0;
}

int getElement(matrix const * mtx, int row, int col,
               double * val) {
  int err = badArgs(mtx, row, col);
  if (err) return err;
  if (!val) return -1;

  *val = getE(mtx, row, col);
  return 0;
}

int printMatrix(matrix const * mtx) {
  int row, col;

  if (!mtx) return -1;

  for (row = 1; row <= mtx->rows; row++) {
    for (col = 1; col <= mtx->cols; col++) {
      /* Print the floating point element with
       *  - either a - if negative of a space if positive
       *  - at least 3 spaces before the .
       *  - precision to the hundredths place */
      printf("% 6.2f ", getE(mtx, row, col));
    }
    /* separate rows by newlines */
    printf("\n");
  }
  return 0;
}

int isSquare(matrix const * mtx) {
  return mtx && mtx->rows == mtx->cols;
}

int product(matrix const * mtx1, matrix const * mtx2,
            matrix * prod) {
  int row, col, k;
  if (!mtx1 || !mtx2 || !prod) return -1;
  if (mtx1->cols != mtx2->rows ||
      mtx1->rows != prod->rows ||
      mtx2->cols != prod->cols)
    return -2;

  for (col = 1; col <= mtx2->cols; col++)
    for (row = 1; row <= mtx1->rows; row++) {
      double val = 0.0;
      for (k = 1; k <= mtx1->cols; k++)
        val += getE(mtx1, row, k) * getE(mtx2, k, col);
      setE(prod, row, col, val);
    }
  return 0;
}

int isIdentity(matrix const * m) {
  int row, col;
  if (!isSquare(m)) return 0;
  for (col = 1; col <= m->cols; col++)
    for (row = 1; row <= m->rows; row++)
      if (row != col) {
        if (getE(m, row, col) != 0.0)
          return 0;
      } else {
        if (getE(m, row, col) != 1.0)
          return 0;
      }
  return 1;
}

int submatrix(matrix const * A, matrix * B, int row, int col) {
  int i, j;
  if (!A || !B || B->rows + row - 1 > A->rows || B->cols + col - 1 > A->cols)
    return -1;
  for (j = 1; j <= B->cols; j++)
    for (i = 1; i <= B->rows; i++)
      setE(B, i, j, getE(A, i + row - 1, j + col - 1));
  return 0;
}

/* Finds a suitable pivot in column j of M and
 * permutes rows if needed to bring said pivot
 * to row j.  Returns 0 if successful and -1 if
 * a pivot is not found.
 */
static int pivot(matrix * M, int j) {
  double val;
  if((val = getE(M, j, j)) == 0){
    // find a row after current that has something other that 0, bring it up, and break
    // if none, return -1
    int i;
    for(i = j + 1; i <= M->rows; i++){
      if((val = getE(M, i, j)) != 0){
        double temp;
        int ii;
        for(ii = 1; ii <= M->cols; ii++){
          temp = getE(M, i, ii);
          setE(M, i, ii, getE(M, j, ii));
          setE(M, j, ii, temp);
        }
        break;
      }
    }
    if(i > M->rows) return -1;
  }
  int i;
  for(i = 0; i <= M->cols; i++)
    setE(M, j, i, getE(M, j, i) / val);
  return 0;
}

/* Puts column j of matrix M in row echelon form.
 * That is, 1 on the diagonal, and 0 below.  The rest
 * of the matrix is adjusted accordingly.
 */
static void rowEchelon(matrix * M, int j) {
  // subtract row from each under it
  int i, ii;
  double val;
  for(i = j+1; i <= M->rows; i++){
    val = getE(M, i, j);
    for(ii = j; ii <= M->cols; ii++)
      setE(M, i, ii, getE(M, i, ii) - getE(M, j, ii) * val);
  }
}

/* Puts column j of matrix M in reduced row
 * echelon form. That is, 1 on the diagonal and 0
 * elsewhere.  The column is supposed to be
 * already in row echelon form.  The rest
 * of the matrix is adjusted accordingly.
 */
static void reducedRowEchelon(matrix * M, int j) {
  int i, ii;
  double val;
  for(i = j-1; i > 0; i--){
    val = getE(M, i, j);
    for(ii = j; ii <= M->cols; ii++)
      setE(M, i, ii, getE(M, i, ii) - getE(M, j, ii) * val);
  }
}

/* Very naive implementation. */
int gaussJordan(matrix const * A, matrix * GJ) {
  int i;
  /* Check for malformed input. */
  if (!A || !GJ || A->rows != GJ->rows || A->cols != GJ->cols)
    return -1;
  if (A->rows > A->cols)
    return -1;
  /* Initialize GJ to a copy of A. */
  for (i = 0; i < A->rows * A->cols; i++)
    GJ->data[i] = A->data[i];
  /* Gaussian elimination. */
  for (i = 1; i <= GJ->rows; i++) {
    if (pivot(GJ, i) == -1)
      return -1; /* rank-deficient */
    rowEchelon(GJ, i);
  }
  /* Zero entries above diagonal. */
  for (i = GJ->rows; i > 0; i--) {
    reducedRowEchelon(GJ, i);
  }
  return 0;
}
