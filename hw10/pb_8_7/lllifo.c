#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "lifo.h"

typedef struct _node {
  struct _node * next;
  void * e;
} node;

static node * newNode(void * e) {
  node * n  = malloc(sizeof(node));
  if (!n) return NULL;
  n->next = NULL;
  n->e = e;
  return n;
}

static void deleteNode(node * n) {
  free(n);
}

struct _lifo {
  int capacity;
  int size;
  node * tail;
};

lifo * newLifo(int capacity) {
  lifo * q = malloc(sizeof(lifo));
  if (!q) return NULL;
  if (capacity <= 0) capacity = -1;
  q->capacity = capacity;
  q->size = 0;
  q->tail = NULL;
  return q;
}

void deleteLifo(lifo * q) {
  if (!q) return;
  node * n = q->tail;
  while (n) {
    node * next = n->next;
    deleteNode(n);
    n = next;
  }
  free(q);
}

int isEmptyLifo(lifo const * q) {
  if (!q) return 1;
  return(q->size == 0);
}

int putLifo(lifo * q, void * e) {
  node * n;
  if (!q) return -1;
  /* Full?  Impossible if q->capacity == -1. */
  if (q->size == q->capacity) return -1;
  n = newNode(e);
  if (!n) return -1;
  if (q->size == 0) {
    /* Both the head and the tail should be NULL. */
    assert(!q->tail);
    /* Set the head to point to n. */
    q->tail = n;
  } else {
    n->next = q->tail;
  }
  /* In any case, n is the new tail. */
  q->tail = n;
  q->size++;
  return 0;
}

int getLifo(lifo * q, void ** e) {
  node * n;
  if (!q || !e) return -1;
  if (isEmptyLifo(q)) { /* nothing to get */
    *e = NULL;
    return -2;
  }
  assert(q->tail); /* should be nonempty here */
  n = q->tail;
  *e = n->e; /* write element */
  if (q->size == 1) {
    assert(!n->next); /* n should have no successor */
    /* Set tail to NULL. */
    q->tail = NULL;
  }
  /* Set the head to n's successor. */
  q->tail = n->next;
  deleteNode(n);
  q->size--;
  return 0;
}

int sizeLifo(lifo const * q) {
  return q->size;
}

int printLifo(lifo const * q, printFn f) {
  node * n;
  int cnt;
  if (!q || !f) return -1;

  cnt = 0;
  for (n = q->tail; n != NULL; n = n->next) {
    /* Print the index of the element. */
    cnt++;
    printf(" %d:", cnt);
    /* Call user-provided f to print the element. */
    f(n->e);
  }
  printf("\n");
  assert(cnt == q->size);

  return 0;
}
