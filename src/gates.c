#include <stdio.h>
#include "graph.h"

int not(int a) {
  return !a;
}

int and(int a, int b) {
  return a && b;
}

int nand(int a, int b) {
  return not(and(a,b));
}

int or(int a, int b) {
  return a || b;
}

int nor(int a, int b) {
  return not(or(a,b));
}

int xor(int a, int b) {
  if (a != b) {
    return 1;
  }
  return 0;
}

int xnor(int a, int b) {
  return not(xor(a,b));
}

int and_n(NodeList *l, InputNode *bits, int NodeCount) {
  int CurBit;
  if (bits == NULL) {
    return -1;
  }
  InputNode *head = bits;
  while (head != NULL) {
    CurBit = GetInput(l, head->data, NodeCount);
    if (CurBit == 0) {
      return 0;
    }
    head = head->next;
  }
  return 1;
}

int or_n(NodeList *l, InputNode *bits, int NodeCount) {
  int CurBit;
  if (bits == NULL) {
    return -1;
  }
  InputNode *head = bits;
  while (head != NULL) {
    CurBit = GetInput(l, head->data, NodeCount);
    if (CurBit == 1) {
      return 1;
    }
    head = head->next;
  }
  return 0;
}
