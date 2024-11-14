//
// Created by Atakan Akyıldız on 14.11.2024.
//
#include <stdio.h>

int mult(int x, int y) {
    if (y == 1) {
        return x;
    }
    return mult(x, y - 1) + x;
}

int main() {
    int x = 5, y = 3;
    printf("%d * %d = %d\n", x, y, mult(x, y));
    return 0;
}
