#include <stdio.h>
#include "gates.h"

int getGateInput(int inputs[]);
int circuit1(int a, int b);
int circuit2(int a, int b);

int main() {
    int input, flag;
    int gateInput[2];

    printf("Input Number to Simulate\n [1] Circuit 1 [2] Circuit 1\n");
    scanf("%d",&input);

    if(input == 1) {
        flag = getGateInput(gateInput);
        if(flag == 0) {
            printf("Output of Circuit 1 is %d.",or(and(gateInput[0],gateInput[1]),and(not(gateInput[0]),not(gateInput[1]))));
        }
    }
    else if(input == 2) {
        flag = getGateInput(gateInput);
        if(flag == 0) {
            printf("Output of Circuit 2 is %d.",or(and(not(gateInput[0]),gateInput[1]),and(gateInput[0],not(gateInput[1]))));
        }
    }
    else {
        printf("Invalid Input");
    }

    return 0;
}

int getGateInput(int inputs[]) {
    printf("Input A: ");
    scanf("%d",&inputs[0]);
    if(inputs[0] != 0 && inputs[0] != 1) {
        printf("Input must be 0 or 1\n");
        return 1;
    }
    printf("Input B: ");
    scanf("%d",&inputs[1]);
    if(inputs[1] != 0 && inputs[1] != 1) {
        printf("Input must be 0 or 1\n");
        return 1;
    }
    return 0;
}