#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_RECTANGLES 100
#define ID_LENGTH 5

// File names are predefined as constants
#define INPUT_FILE "rectangles.in"
#define AREA_OUTPUT_FILE "area.out"
#define PERIMETER_OUTPUT_FILE "perimeter.out"

// Rectangle structure
struct Rectangle {
    char id[ID_LENGTH];
    float x1, y1;
    float x2, y2;
    float area;
    float perimeter;
};

float calculate_area(float x1, float y1, float x2, float y2) {
    return fabs((x2 - x1) * (y2 - y1));
}

float calculate_perimeter(float x1, float y1, float x2, float y2) {
    return 2 * (fabs(x2 - x1) + fabs(y2 - y1));
}

int compare_area(const void *a, const void *b) {
    struct Rectangle *rectA = (struct Rectangle *)a;
    struct Rectangle *rectB = (struct Rectangle *)b;
    return (rectB->area > rectA->area) - (rectB->area < rectA->area);
}

int compare_perimeter(const void *a, const void *b) {
    struct Rectangle *rectA = (struct Rectangle *)a;
    struct Rectangle *rectB = (struct Rectangle *)b;
    return (rectB->perimeter > rectA->perimeter) - (rectB->perimeter < rectA->perimeter);
}

int main(void) {
    struct Rectangle rectangles[MAX_RECTANGLES];
    int rect_count = 0;

    FILE *input_file = fopen(INPUT_FILE, "r");
    if (input_file == NULL) {
        printf("Error opening file: %s\n", INPUT_FILE);
        return 1;
    }

    char id[ID_LENGTH];
    float x, y;
    while (fscanf(input_file, "%s %f %f", id, &x, &y) == 3) {
        int found = -1;

        for (int i = 0; i < rect_count; i++) {
            if (strcmp(rectangles[i].id, id) == 0) {
                found = i;
                break;
            }
        }

        if (found != -1) {
            rectangles[found].x2 = x;
            rectangles[found].y2 = y;
            rectangles[found].area = calculate_area(rectangles[found].x1, rectangles[found].y1, rectangles[found].x2, rectangles[found].y2);
            rectangles[found].perimeter = calculate_perimeter(rectangles[found].x1, rectangles[found].y1, rectangles[found].x2, rectangles[found].y2);
        } else {
            strcpy(rectangles[rect_count].id, id);
            rectangles[rect_count].x1 = x;
            rectangles[rect_count].y1 = y;
            rectangles[rect_count].x2 = x; // Initialize x2 as x
            rectangles[rect_count].y2 = y; // Initialize y2 as y
            rect_count++;
        }
    }
    fclose(input_file);

    qsort(rectangles, rect_count, sizeof(struct Rectangle), compare_area);

    FILE *area_output = fopen(AREA_OUTPUT_FILE, "w");
    if (area_output == NULL) {
        printf("Error opening file: %s\n", AREA_OUTPUT_FILE);
        return 1;
    }
    for (int i = 0; i < rect_count; i++) {
        fprintf(area_output, "%s\n", rectangles[i].id);
    }
    fclose(area_output);

    qsort(rectangles, rect_count, sizeof(struct Rectangle), compare_perimeter);
    FILE *perimeter_output = fopen(PERIMETER_OUTPUT_FILE, "w");
    if (perimeter_output == NULL) {
        printf("Error opening file: %s\n", PERIMETER_OUTPUT_FILE);
        return 1;
    }
    for (int i = 0; i < rect_count; i++) {
        fprintf(perimeter_output, "%s\n", rectangles[i].id);
    }
    fclose(perimeter_output);

    printf("Rectangles sorted and saved to files.\n");

    return 0;
}
