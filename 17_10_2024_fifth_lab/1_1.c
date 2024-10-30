#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100
#define FILENAME "file.txt"
#define MAX_CITIZENS 15

typedef struct {
    char name[MAX_LENGTH];
    char id[10];
    char birth_place[MAX_LENGTH];
    char birth_date[11];
    char issuing[11];
} citizen_t;

int count_citizens() {
    FILE *fptr_out = fopen(FILENAME, "r");
    if (fptr_out == NULL) {
        return 0;
    }

    int count = 0;
    char line[MAX_LENGTH * 5];
    while (fgets(line, sizeof(line), fptr_out)) {
        count++;
    }

    fclose(fptr_out);
    return count;
}

int check_existing_id(const char *search_id) {
    FILE *fptr_out = fopen(FILENAME, "r");
    if (fptr_out == NULL) {
        return 0;
    }

    char line[MAX_LENGTH * 5];
    while (fgets(line, sizeof(line), fptr_out)) {
        char file_name[MAX_LENGTH], file_id[10], file_birth_place[MAX_LENGTH], file_birth_date[11], file_issuing[11];
        sscanf(line, "%s\t%s\t%s\t%s\t%s", file_name, file_id, file_birth_place, file_birth_date, file_issuing);

        if (strcmp(file_id, search_id) == 0) {
            fclose(fptr_out);
            return 1;
        }
    }

    fclose(fptr_out);
    return 0;
}

void search_by_id() {
    char search_id[10];
    printf("Enter the ID to search: ");
    scanf("%s", search_id);

    FILE *fptr_out = fopen(FILENAME, "r");
    if (fptr_out == NULL) {
        printf("File not found\n");
        return;
    }

    int found = 0;
    char line[MAX_LENGTH * 5];
    while (fgets(line, sizeof(line), fptr_out)) {
        char file_name[MAX_LENGTH], file_id[10], file_birth_place[MAX_LENGTH], file_birth_date[11], file_issuing[11];
        sscanf(line, "%[^\t]\t%s\t%[^\t]\t%s\t%s", file_name, file_id, file_birth_place, file_birth_date, file_issuing);

        if (strcmp(file_id, search_id) == 0) {
            printf("Citizen found:\n");
            printf("Name: %s\nID: %s\nBirth Place: %s\nBirth Date: %s\nIssuing: %s\n",
                   file_name, file_id, file_birth_place, file_birth_date, file_issuing);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Citizen with ID %s not found.\n", search_id);
    }

    fclose(fptr_out);
}

int main(void) {
    int choice;
    FILE *fptr_in = fopen(FILENAME, "a");
    if (fptr_in == NULL) {
        printf("File not found\n");
        return -1;
    }
    else {
        printf("File opened for writing\n");
    }

    while (1) {
        printf("Welcome to the National ID System!\n1. Add a new citizen\n2. Search by ID\n"
               "3. List database\n4. Exit\n");
        scanf("%d", &choice);
        switch(choice) {
            case 1: {
                int citizen_count = count_citizens();
                if (citizen_count >= MAX_CITIZENS) {
                    printf("Error: The database is full. Maximum number of citizens (%d) reached.\n", MAX_CITIZENS);
                    break;
                }

                citizen_t s1;
                printf("Enter citizen name: ");
                scanf("%s", s1.name);
                printf("Enter citizen ID: ");
                scanf("%s", s1.id);

                if (check_existing_id(s1.id)) {
                    printf("Error: A citizen with ID %s already exists. Please use a different ID.\n", s1.id);
                    break;
                }

                printf("Enter citizen birth place: ");
                scanf("%s", s1.birth_place);
                printf("Enter citizen birth date (DD/MM/YYYY): ");
                scanf("%s", s1.birth_date);
                printf("Enter citizen Issuing (DD/MM/YYYY): ");
                scanf("%s", s1.issuing);

                fprintf(fptr_in, "%s\t%s\t%s\t%s\t%s\n", s1.name, s1.id, s1.birth_place, s1.birth_date, s1.issuing);
                fflush(fptr_in);

                printf("Citizen added successfully!\n");
                break;
            }

            case 2:
                search_by_id();
                break;

            case 3: {
                FILE *fptr_out = fopen(FILENAME, "r");
                if (fptr_out == NULL) {
                    printf("File not found\n");
                    return -1;
                }

                char line[MAX_LENGTH * 5];
                while (fgets(line, sizeof(line), fptr_out)) {
                    char file_name[MAX_LENGTH], file_id[10], file_birth_place[MAX_LENGTH], file_birth_date[11], file_issuing[11];
                    sscanf(line, "%[^\t]\t%s\t%[^\t]\t%s\t%s", file_name, file_id, file_birth_place, file_birth_date, file_issuing);
                    printf("Name: %s, ID: %s, Birth place: %s, Birth date: %s, Issuing: %s\n",
                           file_name, file_id, file_birth_place, file_birth_date, file_issuing);
                }

                fclose(fptr_out);
                break;
            }

            case 4:
                fclose(fptr_in);
                printf("Ciao ciao!!\n");
                exit(0);

            default:
                printf("ERROR: %d: Incorrect menu option\n", choice);
                exit(0);
        }
    }

    return 0;
}
