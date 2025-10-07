#include <stdio.h>

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