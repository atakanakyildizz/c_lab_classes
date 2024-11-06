#ifndef STUDENT_RECORD_MANAGEMENT_SYSTEM_H
#define STUDENT_RECORD_MANAGEMENT_SYSTEM_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct student_s* student_t;

struct student_s {
    int studentID;            // Unique identifier for each student
    char name[100];           // Full name of the student
    char major[50];           // Major field of study
    int year;                 // Current year of study
    float gpa;                // Current GPA of the student
    student_t next;           // Pointer to the next record
};

student_t student_new(void);
void student_free(student_t s);
void student_add(student_t* head, char* name, char* major, int year, float gpa);
void student_delete(student_t* head, int id);
student_t student_search(student_t head, int id);
void students_display(student_t head);
student_t students_load(const char *filename);  // src yerine filename


#endif
