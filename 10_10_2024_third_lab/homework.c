//
// Created by Atakan Akyıldız on 13.10.2024.
//

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define ALPHABETFILENAME "alphabet.in"

void turn(char message[50], char outputfile[50]) {
    char letter, code[500], alphabet[500];
    FILE *fp = fopen(ALPHABETFILENAME, "r");
    FILE *fptr = fopen(outputfile, "w");
    if(fptr == NULL) {
        printf("Could not open output file\n");
    }
    while(fscanf (fp , "%c\t%s\n", &letter , code) != EOF) {
        for (int i = 0; i < strlen(code); i++) {
            strcpy(alphabet[letter - '  '], code);
        }
        printf("%c", code[0]);
    }


    fclose(fptr);
    fclose (fp);
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
            turn(message, encodedout);

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

}

