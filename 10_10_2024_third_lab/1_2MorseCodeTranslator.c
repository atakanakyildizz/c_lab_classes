#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define ALPHABETFILENAME "alphabet.in"

void encode(char message[500], char outputfile[50]) {
    char letter, code[500], alphabet[128][100];

    FILE *fp = fopen(ALPHABETFILENAME, "r");
    if (fp == NULL) {
        printf("Error opening alphabet file.\n");
        return;
    }

    FILE *fptr = fopen(outputfile, "w");
    if (fptr == NULL) {
        printf("Could not open output file\n");
        fclose(fp);
        return;
    }

    while (fscanf(fp, "%c\t%s\n", &letter, code) != EOF) {
        strcpy(alphabet[letter], code);
    }

    printf("Encoded message: ");
    for (int i = 0; message[i] != '\0'; i++) {
        if (message[i] != ' ') {
            fputs(alphabet[message[i]], fptr);
            printf("%s", alphabet[message[i]]);
        } else {
            fputs(" / ", fptr);
            printf(" / ");
        }
        fputs(" ", fptr);
        printf(" ");
    }

    printf("\n");
    fclose(fptr);
    fclose(fp);
}

void decode(char morseMessage[500], char outputfile[50]) {
    char letter, code[500], alphabet[128][100];

    FILE *fp = fopen(ALPHABETFILENAME, "r");
    if (fp == NULL) {
        printf("Error opening alphabet file.\n");
        return;
    }

    while (fscanf(fp, "%c\t%s\n", &letter, code) != EOF) {
        strcpy(alphabet[letter], code);
    }
    fclose(fp);

    FILE *fptr = fopen(outputfile, "w");
    if (fptr == NULL) {
        printf("Could not open output file\n");
        return;
    }

    printf("Decoded message: ");
    char *token = strtok(morseMessage, " ");
    while (token != NULL) {
        if (strcmp(token, "/") == 0) {
            fputc(' ', fptr);
            printf(" ");
        } else {
            for (letter = 0; letter < 128; letter++) {
                if (strcmp(alphabet[letter], token) == 0) {
                    fputc(letter, fptr);
                    printf("%c", letter);
                    break;
                }
            }
        }
        token = strtok(NULL, " ");
    }

    printf("\n");
    fclose(fptr);
}


int main() {
    char choose;
    char inputFile[50], outputFile[50];
    char message[500];

    while (1) {
        printf("\n(E)ncode (D)ecode e(X)it >>> ");
        scanf(" %c", &choose);

        switch (toupper(choose)) {
            case 'E': {
                printf("Input file name > ");
                scanf("%s", inputFile);
                printf("Output file name > ");
                scanf("%s", outputFile);

                FILE *fp = fopen(inputFile, "r");
                if (fp == NULL) {
                    printf("Error opening file %s\n", inputFile);
                    break;
                }

                fgets(message, sizeof(message), fp);
                printf("Encoded message saved to file %s\n", outputFile);
                fclose(fp);

                encode(message, outputFile);
                break;
            }

            case 'D': {
                printf("Input file name > ");
                scanf("%s", inputFile);
                printf("Output file name > ");
                scanf("%s", outputFile);

                FILE *fp = fopen(inputFile, "r");
                if (fp == NULL) {
                    printf("Error opening file %s\n", inputFile);
                    break;
                }

                fgets(message, sizeof(message), fp);
                printf("Decoded message saved to file %s\n", outputFile);

                decode(message, outputFile);
                fclose(fp);
                break;
            }

            case 'X':
                printf("Exiting...\n");
                return 0;

            default:
                printf("Invalid option.\n");
                break;
        }
    }
    return 0;
}

