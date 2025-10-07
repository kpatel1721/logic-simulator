#include <stdio.h>
#include "gates.h"

int main() {
    char input = '0';
    int a,b;

    while (1) {
        printf("Input Operation:\n[1] Not [2] And [3] Nand [4] Or [5] Nor [6] Xor [7] Xnor [q] Quit\n");
        scanf(" %c",&input);

        if(input == 'q' || input == 'Q') {
            break;
        }
        else if(input == '1') {
            printf("Input A: ");
            scanf("%d",&a);
            if(a != 0 && a != 1) {
                printf("Input must be 0 or 1\n");
                continue;
            }
            printf("Output: %d\nNOT Truth Table\nA | X\n------\n0 | 1\n1 | 0\n", not(a));
        }
        else if(input == '2') {
            printf("Input A: ");
            scanf("%d",&a);
            if(a != 0 && a != 1) {
                printf("Input must be 0 or 1\n");
                continue;
            }
            printf("Input B: ");
            scanf("%d",&b);
            if(b != 0 && b != 1) {
                printf("Input must be 0 or 1\n");
                continue;
            }
            printf("Output: %d\nAND Truth Table\nA B | X\n------\n0 0| 0\n0 1| 0\n1 0| 0\n1 1| 1\n", and(a,b));
        }
        else if(input == '3') {
            printf("Input A: ");
            scanf("%d",&a);
            if(a != 0 && a != 1) {
                printf("Input must be 0 or 1\n");
                continue;
            }
            printf("Input B: ");
            scanf("%d",&b);
            if(b != 0 && b != 1) {
                printf("Input must be 0 or 1\n");
                continue;
            }
            printf("Output: %d\nNAND Truth Table\nA B | X\n------\n0 0| 1\n0 1| 1\n1 0| 1\n1 1| 0\n", nand(a,b));
        }
        else if(input == '4') {
            printf("Input A: ");
            scanf("%d",&a);
            if(a != 0 && a != 1) {
                printf("Input must be 0 or 1\n");
                continue;
            }
            printf("Input B: ");
            scanf("%d",&b);
            if(b != 0 && b != 1) {
                printf("Input must be 0 or 1\n");
                continue;
            }
            printf("Output: %d\nOR Truth Table\nA B | X\n------\n0 0| 0\n0 1| 1\n1 0| 1\n1 1| 1\n", or(a,b));
        }
        else if(input == '5') {
            printf("Input A: ");
            scanf("%d",&a);
            if(a != 0 && a != 1) {
                printf("Input must be 0 or 1\n");
                continue;
            }
            printf("Input B: ");
            scanf("%d",&b);
            if(b != 0 && b != 1) {
                printf("Input must be 0 or 1\n");
                continue;
            }
            printf("Output: %d\nNOR Truth Table\nA B | X\n------\n0 0| 1\n0 1| 0\n1 0| 0\n1 1| 0\n", nor(a,b));
        }
        else if(input == '6') {
            printf("Input A: ");
            scanf("%d",&a);
            if(a != 0 && a != 1) {
                printf("Input must be 0 or 1\n");
                continue;
            }
            printf("Input B: ");
            scanf("%d",&b);
            if(b != 0 && b != 1) {
                printf("Input must be 0 or 1\n");
                continue;
            }
            printf("Output: %d\nXOR Truth Table\nA B | X\n------\n0 0| 0\n0 1| 1\n1 0| 1\n1 1| 0\n", xor(a,b));
        }
        else if(input == '7') {
            printf("Input A: ");
            scanf("%d",&a);
            if(a != 0 && a != 1) {
                printf("Input must be 0 or 1\n");
                continue;
            }
            printf("Input B: ");
            scanf("%d",&b);
            if(b != 0 && b != 1) {
                printf("Input must be 0 or 1\n");
                continue;
            }
            printf("Output: %d\nXNOR Truth Table\nA B | X\n------\n0 0| 1\n0 1| 0\n1 0| 0\n1 1| 1\n", xnor(a,b));
        }
        else {
            printf("Invalid Input\n");
        }
    }
}