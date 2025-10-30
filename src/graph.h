typedef struct node_tag {
  int id;
  char type;
  int input1;
  int input2;
  int output;
  struct node_tag *next;
  struct node_tag *prev;
} Node;

typedef struct {
  Node *first;
  Node *last;
} NodeList;


void InitializeList(NodeList *l);
int CreateCircuitList(FILE *f, NodeList *l);
void PrintCircuit(NodeList *l);
void FreeCircuitList(NodeList *l);
void SimulateCircuit(NodeList *l, int NodeCount);
int GetInput(NodeList *l, int id, int NodeCount);
