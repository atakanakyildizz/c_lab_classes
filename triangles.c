//
// Created by Atakan Akyıldız on 14.11.2024.
//
#include <stdio.h>

void printRowA(int current) {
    for (int i = 0; i < current; i++) {
        printf("%d ", current);
    }
    printf("\n");
}

void triangleA(int n, int current) {
    if (current > n) {
        return;
    }
    printRowA(current);
    triangleA(n, current + 1);
}

void printRowB(int current, int count) {
    if (count >= current) {
        printf("\n");
        return;
    }
    printf("%d ", current);
    printRowB(current, count + 1);
}

void triangleB(int n, int current) {
    if (current > n) {
        return;
    }
    printRowB(current, 0);
    triangleB(n, current + 1);
}

int main() {
    int n;
    printf("Enter a number for triangleA and triangleB: ");
    scanf("%d", &n);

    printf("\nTriangleA (Iterative Inner, Recursive Outer):\n");
    triangleA(n, 1);

    printf("\nTriangleB (Fully Recursive):\n");
    triangleB(n, 1);

    return 0;
}
