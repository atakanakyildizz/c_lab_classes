#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student_record_management_system.h"

int main() {
    student_t studentList = students_load("students.in");
    int choice;

    while (1) {
        printf("Student Records Management System\n");
        printf("1. Add new student record\n");
        printf("2. Delete a student record\n");
        printf("3. Search for a student record\n");
        printf("4. Display all student records\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");

        // Menü seçimlerini almak için güvenli input alıyoruz
        if (scanf("%d", &choice) != 1) {
            while (getchar() != '\n'); // Buffer'ı temizle
            printf("Invalid input. Please try again.\n");
            continue;
        }

        // Menü işlemleri
        switch (choice) {
            case 1: {
                char name[100], major[50];
                int year;
                float gpa;

                // Yeni öğrenci ekleme
                printf("Enter name: ");
                getchar(); // Yeni satır karakterini temizle
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = '\0';  // '\n' karakterini sil

                printf("Enter major: ");
                fgets(major, sizeof(major), stdin);
                major[strcspn(major, "\n")] = '\0';  // '\n' karakterini sil

                printf("Enter year of study: ");
                if (scanf("%d", &year) != 1) {
                    printf("Invalid year. Please try again.\n");
                    continue;
                }

                printf("Enter GPA: ");
                if (scanf("%f", &gpa) != 1) {
                    printf("Invalid GPA. Please try again.\n");
                    continue;
                }

                student_add(&studentList, name, major, year, gpa);
                printf("New student added successfully.\n");
                break;
            }
            case 2: {
                int id;
                printf("Enter student ID to delete: ");
                if (scanf("%d", &id) != 1) {
                    printf("Invalid ID. Please try again.\n");
                    continue;
                }
                student_delete(&studentList, id);
                printf("Student record deleted.\n");
                break;
            }
            case 3: {
                int id;
                printf("Enter student ID to search: ");
                if (scanf("%d", &id) != 1) {
                    printf("Invalid ID. Please try again.\n");
                    continue;
                }
                student_t foundStudent = student_search(studentList, id);
                if (foundStudent != NULL) {
                    printf("Student found:\n");
                    printf("ID: %d, Name: %s, Major: %s, Year: %d, GPA: %.2f\n",
                        foundStudent->studentID, foundStudent->name,
                        foundStudent->major, foundStudent->year, foundStudent->gpa);
                } else {
                    printf("Student not found.\n");
                }
                break;
            }
            case 4: {
                students_display(studentList);
                break;
            }
            case 5:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}
