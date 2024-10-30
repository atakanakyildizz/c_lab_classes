//
// Created by Atakan Akyıldız on 22.10.2024.
//
#include <stdio.h>
#include <stdlib.h>

void sortColumn(int **matrix, int rows, int col) {
    for (int i = 0; i < rows - 1; i++) {
        for (int j = i + 1; j < rows; j++) {
            if (matrix[i][col] > matrix[j][col]) {
                int temp = matrix[i][col];
                matrix[i][col] = matrix[j][col];
                matrix[j][col] = temp;
            }
        }
    }
}

int main() {
    FILE *file, *outputFile;
    char filename[100];
    int **matrix;
    int rows = 0, cols = 0, temp, i, j;

    printf("Enter the filename: ");
    scanf("%s", filename);

    file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return -1;
    }

    while (fscanf(file, "%d", &temp) == 1) {
        cols++;
        if (fgetc(file) == '\n') {
            rows++;
            break;
        }
    }

    while (fscanf(file, "%d", &temp) == 1) {
        if (fgetc(file) == '\n') {
            rows++;
        }
    }

    matrix = (int **)malloc(rows * sizeof(int *));
    for (i = 0; i < rows; i++) {
        matrix[i] = (int *)malloc(cols * sizeof(int));
    }

    rewind(file);
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            fscanf(file, "%d", &matrix[i][j]);
        }
    }

    fclose(file);

    for (j = 0; j < cols; j++) {
        sortColumn(matrix, rows, j);
    }

    outputFile = fopen("output.out", "w");
    if (outputFile == NULL) {
        perror("Error opening output file");
        return -1;
    }

    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            fprintf(outputFile, "%d ", matrix[i][j]);
        }
        fprintf(outputFile, "\n");
    }

    printf("Output stored in output.out file.\n");

    for (i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
    fclose(outputFile);

    return 0;
}
