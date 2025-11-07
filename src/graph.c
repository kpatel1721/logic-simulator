#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "graph.h"
#include "gates.h"

void InitializeList(NodeList *l) {
  l->first = l->last = NULL;
}

int CreateCircuitList(FILE *f, NodeList *l) {
  char buffer[64];
  int i;

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

    Node *n = malloc(sizeof(Node));
    if (n == NULL) {
      printf("Malloc Failed");
      exit(1);
    }

    n->output = 0;

    int j, t = 0, IDFlag = 0, FirstInputFlag = 0;
    char temp[20];
    InputNode *tail = NULL;
    for (j = 0; buffer[j] != '\0'; j++) {
      if (buffer[j] == 'I' || buffer[j] == 'N' || buffer[j] == 'A' || buffer[j] == 'O' || buffer[j] == 'X' || buffer[j] == 'Q') {
        n->type = buffer[j];
      }
      else if (buffer[j] >= '0' && buffer[j] <= '9') {
        if (t < (int)sizeof(temp) - 1) {
          temp[t++] = buffer[j];
        }
      }
      else if (t > 0) {
        temp[t] = '\0';
        if (IDFlag == 0) {
          n->id = atoi(temp);
          IDFlag = 1;
        }
        else {
          InputNode *CurInput = malloc(sizeof(InputNode));
          if (CurInput == NULL) {
            printf("Malloc Failed\n");
            exit(1);
          }
          CurInput->data = atoi(temp);
          CurInput->next = NULL;
          if (FirstInputFlag == 0) {
            n->input = CurInput;
            tail = CurInput;
            FirstInputFlag = 1;
          } else {
            tail->next = CurInput;
            tail = CurInput;
          }
        }
        t = 0;
      }
    }

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
  return NodeCount;
}

void PrintCircuit(NodeList *l) {
  Node *head = l->first;
  while (head != NULL) {
    printf("Id: %d Type: %c Inputs:", head->id, head->type);
    InputNode *in = head->input;
    if (in == NULL) {
      printf(" (none)");
    } else {
      while (in != NULL) {
        printf(" %d", in->data);
        in = in->next;
      }
    }
    printf("\n");
    head = head->next;
  }
}

void FreeCircuitList(NodeList *l) {
  Node* current = l->first;
  Node* next;

  while (current != NULL) {
    next = current->next;
    InputNode *in = current->input;
    while (in != NULL) {
      InputNode *in_next = in->next;
      free(in);
      in = in_next;
    }
    free(current);
    current = next;
  }
}

void SimulateCircuit(NodeList *l, int NodeCount) {
  Node *head = l->first;
  int input1, input2;

  while (head != NULL) {
    if (head->type == 'I') {
      printf("Enter input 0 or 1 for ID: %d\n", head->id);
      scanf("%d", &head->output);
      while (head->output != 0 && head->output != 1) {
        printf("Invalid Input Try Again\n");
        scanf("%d", &head->output);
      }
    }
    else if (head->type == 'A') {
      input1 = GetInput(l, head->input->data, NodeCount);
      input2 = GetInput(l, head->input->next->data, NodeCount);
      head->output = and(input1, input2);
    }
    else if (head->type == 'O') {
      input1 = GetInput(l, head->input->data, NodeCount);
      input2 = GetInput(l, head->input->next->data, NodeCount);
      head->output = or(input1, input2);
    }
    else if (head->type == 'X') {
      input1 = GetInput(l, head->input->data, NodeCount);
      input2 = GetInput(l, head->input->next->data, NodeCount);
      head->output = xor(input1, input2);
    }
    else if (head->type == 'N') {
      input1 = GetInput(l, head->input->data, NodeCount);
      head->output = not(input1);
    }
    else if (head->type == 'Q') {
      input1 = GetInput(l,head->input->data, NodeCount);
      printf("Output at Id %d: %d\n", head->id, input1);
    }
    head = head->next;
  }
  return;
}

int GetInput(NodeList *l, int id, int NodeCount) {
  if (id <= NodeCount/2) {
    Node *head = l->first;
    while (head != NULL) {
      if (head->id == id) {
        return head->output;
      }
      head = head->next;
    }
  }
  else {
    Node *head = l->last;
    while (head != NULL) {
      if (head->id == id) {
        return head->output;
      }
      head = head->prev;
    }
  }
  // Should never reach this
  return -1;
}
