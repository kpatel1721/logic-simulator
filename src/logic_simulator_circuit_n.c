#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "gates.h"

void getUserBits(int a[], int b[], int size);
void getRandomBits(int a[], int b[], int size);
int circuit_1(const int a[], const int b[], int n);
int circuit_2(const int a[], const int b[], int n);

int main() {
    int circuitChoice, inputSize, choice;
    printf("Which circuit do you want to simulate? [1] Circuit 1 (8 inputs) [2] Circuit 2 (16 inputs)\n");
    scanf("%d", &circuitChoice);
    if (circuitChoice == 1) {
        inputSize = 8;
    }
    else if (circuitChoice == 2) {
        inputSize = 16;
    }
    else {
        printf("Invalid Input\n");
        return 1;
    }

    int *a = (int *)malloc(inputSize * sizeof(int));
    if (a == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }
    int *b = (int *)malloc(inputSize * sizeof(int));
    if (b == NULL) {
        printf("Memory allocation failed.\n");
        free(a);
        return 1;
    }

    printf("Do you want to enter your own inputs or use random inputs?\n [1] User Inputs [2] Random Inputs\n");
    scanf("%d", &choice);
    if (choice == 1) {
        getUserBits(a, b, inputSize);
    }
    else if (choice == 2) {
        getRandomBits(a, b, inputSize);
    }
    else {
        printf("Invalid Input\n");
        free(a);
        free(b);
        return 1;
    }

    if (circuitChoice == 1) {
        printf("Output of Circuit 1 is %d.\n", circuit_1(a, b, inputSize));
    }
    else if (circuitChoice == 2) {
        printf("Output of Circuit 2 is %d.\n", circuit_2(a, b, inputSize));
    }
    free(a);
    free(b);
    return 0;
}

void getUserBits(int a[], int b[], int size) {
    int input, i;
    printf("Enter %d bits for A (0 or 1):\n", size);
    for (i = 0; i < size; i++) {
        scanf("%d", &input);
        while (input != 0 && input != 1) {
            printf("Input must be 0 or 1. Please re-enter:\n");
            scanf("%d", &input);
        }
        a[i] = input;
    }
    printf("Enter %d bits for B (0 or 1):\n", size);
    for (i = 0; i < size; i++) {
        scanf("%d", &input);
        while (input != 0 && input != 1) {
            printf("Input must be 0 or 1. Please re-enter:\n");
            scanf("%d", &input);
        }
        b[i] = input;
    }
}

void getRandomBits(int a[], int b[], int size) {
    int i;
    srand((unsigned int)time(NULL));
    for (i = 0; i < size; i++) {
        a[i] = rand() % 2;
        b[i] = rand() % 2;
    }
}

int circuit_1(const int a[], const int b[], int n) {
    /*
    * buffer can be ignored since input is the same as the output just delay circuit
    * which does not matter for this implementation
    */
    int and[8] = {a[0], a[1], a[2], a[3], b[0], b[1], b[2], b[3]};
    int or[8] = {a[4], a[5], a[6], a[7], b[4], b[5], b[6], b[7]};
    return xnor(and_n(and, 8), or_n(or, 8));
}

int circuit_2(const int a[], const int b[], int n){
    int and1[8] = {a[12], a[13], a[14], a[15], b[0], b[1], b[2], b[3]};
    int or1[8] = {a[8], a[9], a[10], a[11], b[4], b[5], b[6], b[7]};
    int or2[8] = {a[4], a[5], a[6], a[7], b[8], b[9], b[10], b[11]};
    int and2[8] = {a[0], a[1], a[2], a[3], b[12], b[13], b[14], b[15]};
    return or(or(and_n(and1,n),or_n(or1,n)),and(or_n(or2,n),and_n(and2,n)));
}