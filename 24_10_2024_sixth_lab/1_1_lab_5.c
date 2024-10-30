//
// Created by Atakan Akyıldız on 28.10.2024.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILENAME "cyclist.txt"
#define MAX_NAME_LENGTH 30
#define MAX_LAPS 100
#define MAX_ATHLETES 50


struct Athlete {
    char name[MAX_NAME_LENGTH];
    int id;
    int laps;
    float lap_times[MAX_LAPS];
};

// Prototipler
void list_athletes(struct Athlete athletes[], int count);
void detail_athlete(struct Athlete athletes[], int count, const char *name);
void best_athlete(struct Athlete athletes[], int count);
float calculate_average(float times[], int laps);

int main(void) {
    struct Athlete athletes[MAX_ATHLETES];
    int athlete_count = 0;
    char command[20];
    char name[MAX_NAME_LENGTH];

    FILE *fp = fopen(FILENAME, "r");
    if (fp == NULL) {
        printf("Error with opening file \n");
        exit(1);
    }

    fscanf(fp, "%d", &athlete_count);

    for (int i = 0; i < athlete_count; i++) {
        fscanf(fp, "%s %d %d", athletes[i].name, &athletes[i].id, &athletes[i].laps);
        for (int j = 0; j < athletes[i].laps; j++) {
            fscanf(fp, "%f", &athletes[i].lap_times[j]);
        }
    }
    fclose(fp);

    while (1) {
        printf("Command? ");
        scanf("%s", command);

        if (strcmp(command, "list") == 0) {
            list_athletes(athletes, athlete_count);
        } else if (strcmp(command, "detail") == 0) {
            scanf("%s", name);
            detail_athlete(athletes, athlete_count, name);
        } else if (strcmp(command, "best") == 0) {
            best_athlete(athletes, athlete_count);
        } else if (strcmp(command, "stop") == 0) {
            printf("Program ended.\n");
            break;
        } else {
            printf("Not validated. Try again.\n");
        }
    }

    return 0;
}

void list_athletes(struct Athlete athletes[], int count) {
    printf("Number of athletes: %d\n", count);
    for (int i = 0; i < count; i++) {
        printf("Name: %s, #ID: %d, #Laps: %d\n", athletes[i].name, athletes[i].id, athletes[i].laps);
    }
}

void detail_athlete(struct Athlete athletes[], int count, const char *name) {
    for (int i = 0; i < count; i++) {
        if (strcmp(athletes[i].name, name) == 0) {
            printf("ID: %d, #Laps: %d, #Times: ", athletes[i].id, athletes[i].laps);
            for (int j = 0; j < athletes[i].laps; j++) {
                printf("%.2f ", athletes[i].lap_times[j]);
            }
            printf("\n");
            return;
        }
    }
    printf("Couldn't find athletes: %s\n", name);
}

void best_athlete(struct Athlete athletes[], int count) {
    int best_index = -1;
    float best_avg = 1e9; // Çok büyük bir başlangıç değeri

    for (int i = 0; i < count; i++) {
        float avg = calculate_average(athletes[i].lap_times, athletes[i].laps);
        if (avg < best_avg) {
            best_avg = avg;
            best_index = i;
        }
    }

    if (best_index != -1) {
        printf("Best athletes: %s, #ID: %d, #Laps: %d, #Times: ",
               athletes[best_index].name, athletes[best_index].id, athletes[best_index].laps);
        for (int j = 0; j < athletes[best_index].laps; j++) {
            printf("%.2f ", athletes[best_index].lap_times[j]);
        }
        printf("(Average: %.2f)\n", best_avg);
    }
}

float calculate_average(float times[], int laps) {
    float sum = 0.0;
    for (int i = 0; i < laps; i++) {
        sum += times[i];
    }
    return sum / laps;
}
