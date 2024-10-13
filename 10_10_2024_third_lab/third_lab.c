#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>



//Question 1.1/a
/*int main() {
    char str[100];
    printf("Please choose the quantity of tokens to deposit : ");
    scanf("%s", str);
    int n;
    n =atoi(str);
    printf("The tokens value you entered is : %d\n",n);
}*/

//Question 1.1/b
/*int main() {
    char deposit[4];
    float amount;
    printf("Enter the amount you wish to deposit :");
    scanf("%s", deposit);
    amount = atof(deposit);
    printf("You deposited : %.2f", amount);
}*/

//Question 1.1/cd
/*
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
}*/
//Question 1.1/e
/*
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
*/

//Question 1.2
#define FILENAME_SIZE 1024
void readfromalphabet(char filename[FILENAME_SIZE]);

int main() {
    char choose;

    while (1) {
        printf("\nEncode(E) Decode(D) Exit(X) >>> ");
        scanf("%c", &choose);
        switch (toupper(choose)) {
            char encodedin[20], encodedout[20], message[50];
            case 'E':
                printf("Encoding\n");
                printf("Input file name >");
                scanf("%s", &encodedin);
                printf("Output file name > ");
                scanf("%s", &encodedout);
                printf("\nEncoded message saved to file %s\n", encodedout);
                FILE *fp = fopen(encodedin, "r");
                if (fp == NULL) {
                    printf("Error opening file %s\n", encodedin);
                    fclose(fp);
                }
                else{
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
                exit(0);

            case 'D':
                printf("Decoding\n");
                printf("Input file name >");
                scanf("%s", &encodedin);
                printf("Output file name > ");
                scanf("%s", &encodedout);
                printf("\nDecoded message saved to file %s\n", encodedout);
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
                exit(0);
            case 'X':
                printf("Exiting");
                exit(0);
        }
    }
    readfromalphabet("alphabet.in");
}


#define MAX_LINE 2048

void readfromalphabet(char filename[FILENAME_SIZE]) {

  FILE *file;
  char buffer[MAX_LINE];

  int read_line = 0;

  printf("Read Line: ");
  scanf("%d", &read_line);

  file = fopen(filename, "r");

  // if the file failed to open, exit with an error message and status
  if (file == NULL)
  {
    printf("Error opening file.\n");
    return;
  }
    bool keep_reading = true;
  int current_line = 1;
  do
  {
    // read the next line from the file, store it into buffer
    fgets(buffer, MAX_LINE, file);

    // if we've reached the end of the file, we didn't find the line
    if (feof(file))
    {
      // stop reading from the file, and tell the user the number of lines in
      // the file as well as the line number they were trying to read as the
      // file is not large enough
      keep_reading = false;
      printf("File %d lines.\n", current_line-1);
      printf("Couldn't find line %d.\n", read_line);
    }
    // if we've found the line the user is looking for, print it out
    else if (current_line == read_line)
    {
      keep_reading = false;
      printf("Line:\n%s", buffer);
    }

    // continue to keep track of the current line we are reading
    current_line++;

  } while (keep_reading);

  // close our access to the file
  fclose(file);

  // notably at this point in the code, buffer will contain the line of the
  // file we were looking for if it was found successfully, so it could be
  // used for other purposes at this point as well...

  return;
}

