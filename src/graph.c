#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "graph.h"

void InitializeList(NodeList *l) {
  l->first = l->last = NULL;
}

void CreateCircuitList(FILE *f, NodeList *l) {
  char buffer[64];
  int id, in1, in2, i;
  char type;

  if (fgets(buffer, sizeof(buffer), f) == NULL) {
    printf("Empty File");
    exit(0);
  }
  int NodeCount = atoi(buffer);

  for (i = 0; i < NodeCount; i++) {
    if (fgets(buffer, sizeof(buffer), f) == NULL) {
      break;
    }

    if(strlen(buffer) <= 1){
      continue;
    }

    // Ask if you can use this or figure out how to replace it
    if (sscanf(buffer, "%d: %c %d %d", &id, &type, &in1, &in2) != 4) {
      printf("Warning invalidline: %s", buffer);
      continue;
    }

    Node *n = malloc(sizeof(Node));
    if (n == NULL) {
      printf("Malloc Failed");
      exit(1);
    }

    n->id = id;
    n->type = type;
    n->input1 = in1;
    n->input2 = in2;
    if (l->first == NULL) {
      n->prev = n->next = NULL;
      l->first = l->last = n;
    }
    else {
      n->prev = l->last;
      n->next = NULL;
      l->last->next = n;
      l->last = n;
    }
  }

  }

void PrintCircuit(NodeList *l) {
  Node *head = l->first;
  while (head != NULL) {
    printf("Id: %d Type: %c Input: %d %d\n", head->id, head->type, head->input1, head->input2);
    head = head->next;
  }
}

void FreeCircuitList(NodeList *l) {
  Node* current = l->first;
  Node* next;

  while (current != NULL) {
    next = current->next;
    free(current);
    current = next;
  }
}
