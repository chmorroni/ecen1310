#include <stdio.h>
#include <stdlib.h>

#include "lifo.h"

struct _lifo {
  unsigned capacity;
  unsigned head;
  unsigned tail;
  void * data[1];
};

lifo * newLifo(int capacity) {
  lifo * q;
  if (capacity < 1) return NULL;

  /* The capacity of this buffer is one less than
   * one would think: if the user wants a given
   * capacity, the required array is one cell larger.
   */
  capacity++;

  /* allocate one chunk of memory */
  q = malloc(sizeof(lifo) +
             (capacity-1) * sizeof(void *));
  if (!q) return NULL;
  q->capacity = (unsigned) capacity;
  q->head = q->tail = 0;
  return q;
}

void deleteLifo(lifo * q) {
  free(q);
}

int isEmptyLifo(lifo const * q) {
  if (!q) return 1;
  return q->head == q->tail;
}

int putLifo(lifo * q, void * e) {
  if (!q) return -1;
  if ((q->head+1) % q->capacity == q->tail) /* full? */
    return -1;
  q->data[q->head] = e;
  q->head = (q->head+1) % q->capacity;
  return 0;
}

int getLifo(lifo * q, void ** e) {
  if (!q) return -1;
  if (!e) return -1;
  if (isEmptyLifo(q)) {
    *e = NULL;
    return -2;
  }
  *e = q->data[q->head-1];
  q->head = (q->head-1) % q->capacity;
  return 0;
}

int sizeLifo(lifo const * q) {
  if (q->head >= q->tail)
    return (int) (q->head - q->tail);
  else
    return (int) (q->capacity - q->tail + q->head); 
}

int printLifo(lifo const * q, printFn f) {
  unsigned i, cnt;
  if (!q) return -1;
  if (!f) return -1;
  cnt = 1;
  for (i = q->tail; i != q->head; i = (i+1) % q->capacity) {
    printf(" %d:", cnt);
    f(q->data[i]);
    cnt++;
  }
  printf("\n");
  return 0;
}
