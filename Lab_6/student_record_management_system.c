#include "student_record_management_system.h"

// Function to create a new student record
student_t student_new(void) {
    student_t new_student = (student_t)malloc(sizeof(struct student_s));
    if (new_student == NULL) {
        printf("Memory allocation failed!\n");
        return NULL;
    }
    new_student->next = NULL;
    return new_student;
}

// Function to free a student's memory
void student_free(student_t s) {
    free(s);
}

// Function to add a student to the list
void student_add(student_t *head, char *name, char *major, int year, float gpa) {
    student_t newStudent = student_new();
    if (newStudent == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    // Yeni öğrenci için ID'yi hesapla
    newStudent->studentID = 1;
    if (*head != NULL) {
        student_t temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        newStudent->studentID = temp->studentID + 1;  // Son öğrenci ID'si +1
    }

    // Öğrenci bilgilerini dolduruyoruz
    strcpy(newStudent->name, name);
    strcpy(newStudent->major, major);
    newStudent->year = year;
    newStudent->gpa = gpa;
    newStudent->next = *head;
    *head = newStudent;

    // Öğrenci verilerini dosyaya kaydediyoruz
    FILE *file = fopen("students.in", "a");
    if (!file) {
        printf("Error opening file for appending.\n");
        return;
    }

    fprintf(file, "%s, %s, %d, %.2f\n", newStudent->name, newStudent->major, newStudent->year, newStudent->gpa);
    fclose(file);

    printf("New student added successfully.\n");
}



// Function to delete a student by ID
void student_delete(student_t *head, int id) {
    student_t current = *head;
    student_t prev = NULL;

    // ID'ye sahip öğrenci kaydını buluyoruz
    while (current != NULL && current->studentID != id) {
        prev = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Student not found.\n");
        return;
    }

    // Öğrenci kaydını bağlıyoruz (bağlantıyı kesiyoruz)
    if (prev == NULL) {
        *head = current->next;
    } else {
        prev->next = current->next;
    }

    student_free(current);

    // Dosyayı yeniden yazıyoruz
    FILE *file = fopen("students.in", "w");
    if (!file) {
        printf("Error opening file for writing.\n");
        return;
    }

    current = *head;
    while (current != NULL) {
        fprintf(file, "%s, %s, %d, %.2f\n", current->name, current->major, current->year, current->gpa);
        current = current->next;
    }

    fclose(file);
    printf("Student deleted successfully.\n");
}



// Function to search for a student by ID
student_t student_search(student_t head, int id) {
    student_t current = head;
    while (current != NULL) {
        if (current->studentID == id) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

// Function to display all students
void students_display(student_t head){
        if (head == NULL) {
            printf("No students to display.\n");
            return;
        }

        student_t current = head;
        while (current != NULL) {
            printf("ID: %d, Name: %s, Major: %s, Year: %d, GPA: %.2f\n",
                   current->studentID, current->name, current->major,
                   current->year, current->gpa);
            current = current->next;
        }
    }



// Function to load students from a file
student_t students_load(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Error opening file for reading.\n");
        return NULL;
    }

    student_t head = NULL, current = NULL;
    char name[100], major[50];
    int year;
    float gpa;
    int studentID = 1;  // Başlangıç ID'si

    while (fscanf(file, "%99[^,], %49[^,], %d, %f\n", name, major, &year, &gpa) == 4) {
        student_t newStudent = student_new();
        if (newStudent == NULL) {
            printf("Memory allocation failed.\n");
            fclose(file);
            return head;
        }

        newStudent->studentID = studentID++;  // Her öğrenciye artan ID veriyoruz
        strcpy(newStudent->name, name);
        strcpy(newStudent->major, major);
        newStudent->year = year;
        newStudent->gpa = gpa;
        newStudent->next = NULL;

        if (head == NULL) {
            head = newStudent;
        } else {
            current->next = newStudent;
        }
        current = newStudent;
    }

    fclose(file);
    return head;
}






