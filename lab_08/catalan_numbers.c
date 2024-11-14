//
// Created by Atakan Akyıldız on 14.11.2024.
//
#include <stdio.h>

int catalan(int n) {
    // Base case: C0 = 1
    if (n == 0) {
        return 1;
    }

    int result = 0;
    for (int i = 0; i < n; i++) {
        result += catalan(i) * catalan(n - 1 - i);
    }
    return result;
}

int main() {
    for (int i = 0; i < 10; i++) {
        printf("C%d = %d\n", i, catalan(i));
    }
    return 0;
}
