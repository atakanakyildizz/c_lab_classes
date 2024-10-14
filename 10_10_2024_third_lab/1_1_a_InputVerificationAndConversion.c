#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

//Question 1.1/a

int main() {
    char str[100];
    printf("Please choose the quantity of tokens to deposit : ");
    scanf("%s", str);
    int n;
    n =atoi(str);
    printf("The tokens value you entered is : %d\n",n);
}