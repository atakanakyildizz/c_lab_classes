#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

//Question 1.1/e

int main() {
    char digit[100];
    printf("Digit (Y) to continue and (N) to quit : ");
    scanf("%s", digit);
    while (tolower(digit[0]) != 'n') {
        printf("Continuing the application ...\n");
        printf("Digit (Y) to continue and (N) to quit : ");
        scanf("%s", digit);
    }
    printf("Quitting ...\n");
}

