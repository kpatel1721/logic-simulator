#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#include "gates.h"

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Added Circuit File as arguement");
    return 1;
  }

  FILE *logicCircuit = fopen(argv[1],"r");
  if (logicCircuit == NULL) {
    printf("File failed to open");
    return 1;
  }

  NodeList list;
  InitializeList(&list);

  CreateCircuitList(logicCircuit, &list);
  PrintCircuit(&list);





  FreeCircuitList(&list);
  fclose(logicCircuit);
  return 0;
}
