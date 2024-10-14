#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

//Question 1.1/cd

int main() {
    char passNum[6];
    int counter = 0;
    printf("Please enter the passport number:");
    scanf("%s", passNum);
    for (int i = 0; i < strlen(passNum); i++) {
        if(i <= 1) {
            if (passNum[i] >= 'A' && passNum[i] <= 'Z')
                counter++;
        }
        if(i > 1) {
            if (passNum[i] >= '0' && passNum[i] <= '9')
                counter++;
        }
    }

    if (counter == 9)
        printf("The passport you entered is : %s", passNum);
    else {
        printf("The passport you entered is invalid.");
    }
}