#include <assert.h>
#include <stdlib.h>

void swap3(int * a, int * b, int * c) {
  assert (a != NULL && b != NULL && c != NULL);
  int t = *a;
  *a = *c;
  *c = *b;
  *b = t;
}

int main(void) {
  int a = 0, b = 1, c = 2;
  swap3(&a, &b, &c);
  assert (a == 2 && b == 0 && c == 1);
  return 0;
}
