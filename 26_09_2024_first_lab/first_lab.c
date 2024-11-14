//
// Created by Atakan Akyıldız on 26.09.2024.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//Question 1.1
/*
int folder1_2() {
    int number, predict;
    int i = 0;
    number = rand() % 100;
    printf(" Number Guessing Game−−−−−−−−−−−−−−−−−−−− \n"
           "I have chosen a secret number between 1 and 100. \n");

    printf("Your guess : ");
    scanf("%d", &predict);
    while (number != predict) {
        if (number < predict) {
            printf("Hint : Too high !\n");
            printf("Your guess : ");
            scanf("%d", &predict);
            i++;
        }
        else if (number > predict) {
            printf("Hint : Too low !\n");
            printf("Your guess : ");
            scanf("%d", &predict);
            i++;
        }
        else if (number == predict) {
            printf("Hint : Just right!");
            printf("Congratulations ! You guessed the number in %d tries.", i);
            break;
        }
    }
    return 0;
}*/

//Question 1.2
/*int folder1_2() {
    int balance = 500;
    int option, change;

    printf(" A&P Bank Virtual ATM: \nCurrent Balance: %d", balance);
    printf("Please choose an option: \n1 . Deposit funds\n2 . Withdraw funds"
           "\n3 . Check balance\n4 . Exit \nYour choice : ");
    scanf("%d", &option);
    while (option != 4){
        switch (option) {
            case 1:
                printf("Enter the amount you wish to deposit : ");
                scanf("%d", &change);
                balance += change;
                printf("The transaction is successful ! New balance : %d\n", balance);
                printf("Please choose an option: \n1 . Deposit funds\n2 . Withdraw funds"
                "\n3 . Check balance\n4 . Exit \nYour choice : ");
                scanf("%d", &option);
            case 2:
                printf("Enter the amount you wish to withdraw : ");
                scanf("%d", &change);
                balance -= change;
                printf("The transaction is successful ! New balance : %d\n", balance);
                printf("Please choose an option: \n1 . Deposit funds\n2 . Withdraw funds"
                "\n3 . Check balance\n4 . Exit \nYour choice : ");
                scanf("%d", &option);
            case 3:
                printf("Your balance is: %d\n", balance);
                printf("Please choose an option: \n1 . Deposit funds\n2 . Withdraw funds"
                "\n3 . Check balance\n4 . Exit \nYour choice : ");
                scanf("%d", &option);

            case 4:
                break;

        }
    }
}*/

//Question 1.3
/*int folder1_2() {
    int marbles = 57;
    int choice;
    int first_player = rand()%1;
    int i = 0;

    printf("%d\n", first_player);
    if (first_player == 0) {
        printf("The initial pile has %d marbles .\nyou will play first.\n", marbles);
        while (marbles > 1) {
            printf("Your turn! How many marbles will you take (1−%d)?", marbles/2);
            scanf("%d", &choice);
            marbles -= choice;
            i++;
            printf("There are %d marbles left \n", marbles);

            choice = rand() % marbles/2 +1;
            printf("Computer took %d\n",choice);
            marbles -= choice;
            i++;
            printf("There are %d marbles left \n", marbles);
        }
        if(i % 2 == 0 ) {
            printf("You won");
        }
    }
    else {
        printf("The initial pile has %d marbles .\nI will play first.\n", marbles);
        while (marbles > 0) {
            choice = rand() % marbles/2 +1;
            printf("Computer took %d\n",choice);
            marbles -= choice;
            i++;
            printf("There are %d marbles left \n", marbles);

            printf("Your turn! How many marbles will you take (1−%d)?", marbles/2);
            scanf("%d", &choice);
            marbles -= choice;
            i++;
            printf("There are %d marbles left \n", marbles);
        }
        if(i % 2 == 0 ) {
            printf("Computer won");
        }
    }
}*/

//Homework 2
    int main() {
        char first_string, second_string;
        printf("Hamming Distance Calculator for DNA Strands\n"
               "Please enter the first DNA strand :");
        scanf("%c", &first_string);
        printf("Please enter the second DNA strand :");
        scanf("%c", &first_string);
        for (int i = 0; i < strlen(first_string); i++) {
            if (first_string[i] == second_string[i]) {
                printf(i);
    }



