//
// Created by Atakan Akyıldız on 13.10.2024.
//

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define FILENAME "alphabet.in"

void turn(char message[50]) {
    char letter, code[26], alphabet[26];

    FILE *fp = fopen("alphabet.in", "r");
    while(fscanf (fp , "%c\t%s\n", &letter , code) != EOF) {
        strcpy(alphabet[letter - '  '] , code );
    }
    fclose (fp);
    for (int i = 0; i < strlen(alphabet); i++) {
        printf("%c\n", alphabet[i]);
    }
}


int main() {
    char choose;
    char encodedin[20], encodedout[20];

    printf("Encode(E) Decode(D) Exit(X) >>> ");
    scanf("%c", &choose);
    char message[50];

    switch (toupper(choose)) {
        case 'E':
            printf("Input file name >");
        scanf("%s", &encodedin);
        printf("Output file name > ");
        scanf("%s", &encodedout);
        printf("Encoded message saved to file %s\n", encodedout);

        FILE *fp = fopen(encodedin, "r");
        if (fp == NULL) {
            printf("Error opening file %s\n", encodedin);
            fclose(fp);
        }
        else {
            fgets(message, sizeof(message), fp);
            printf("Encoded message:%s", message);
            FILE *fptr = fopen(encodedout, "w");
            if (fptr == NULL) {
                printf("Error opening file %s\n", encodedout);
            }
            else {
                fputs(message, fptr);
                fclose(fptr);
            }
            fclose(fp);
        }
        break;;

        case 'D':
            printf("Input file name >");
        scanf("%s", &encodedin);
        printf("Output file name > ");
        scanf("%s", &encodedout);
        printf("Decoded message saved to file %s\n", encodedout);
        printf("Decoded message:");

        FILE *fpt = fopen(encodedin, "r");
        if (fpt == NULL) {
            printf("Error opening file %s\n", encodedin);
            fclose(fpt);
        }
        else{
            fgets(message, sizeof(message), fpt);
            printf("Encoded message:%s", message);
            FILE *fptr = fopen(encodedout, "w");
            if (fptr == NULL) {
                printf("Error opening file %s\n", encodedout);
            }
            else {
                fputs(message, fptr);
                fclose(fptr);
            }
            fclose(fpt);
        }
        break;
        case 'X':
            printf("Exiting");
        break;
    }
    turn(message);

}

