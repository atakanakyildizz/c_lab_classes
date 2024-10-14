#include <stdio.h>
#include <stdlib.h>

//Question 1.1/b
int main() {
    char deposit[4];
    float amount;
    printf("Enter the amount you wish to deposit :");
    scanf("%s", deposit);
    amount = atof(deposit);
    printf("You deposited : %.2f", amount);
}