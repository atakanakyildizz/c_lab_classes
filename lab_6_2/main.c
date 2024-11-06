#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int n_columns;    // Satırdaki sütun sayısı
    double *values;   // Satırdaki değerleri tutan dizi
} row;

typedef struct {
    int n_lines;      // CSV'deki satır sayısı
    int n_header;     // Başlık satırı sayısı
    char *sep;        // Ayraç
    row *matrix;      // Satırları içeren matris
} csv;

void read_csv(csv *csv_data, char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Dosya açılamadı");
        exit(EXIT_FAILURE);
    }

    char line[1024];
    int line_count = 0, matrix_size = 10; // Başlangıçta küçük bir boyut belirle

    // Matris için başlangıç belleği ayır
    csv_data->matrix = malloc(matrix_size * sizeof(row));
    csv_data->n_lines = 0;

    while (fgets(line, sizeof(line), file)) {
        if (line_count < csv_data->n_header) { // Başlık satırlarını atla
            line_count++;
            continue;
        }

        // Matris boyutunu kontrol et ve gerekirse yeniden belleği genişlet
        if (csv_data->n_lines >= matrix_size) {
            matrix_size *= 2;
            csv_data->matrix = realloc(csv_data->matrix, matrix_size * sizeof(row));
        }

        // Satırdaki değerleri ayır ve oku
        char *token = strtok(line, csv_data->sep);
        int column_count = 0, values_size = 10;
        csv_data->matrix[csv_data->n_lines].values = malloc(values_size * sizeof(double));

        while (token) {
            if (column_count >= values_size) {
                values_size *= 2;
                csv_data->matrix[csv_data->n_lines].values = realloc(csv_data->matrix[csv_data->n_lines].values, values_size * sizeof(double));
            }

            csv_data->matrix[csv_data->n_lines].values[column_count++] = atof(token) + 1; // Değeri 1 artır
            token = strtok(NULL, csv_data->sep);
        }

        csv_data->matrix[csv_data->n_lines].n_columns = column_count;
        csv_data->n_lines++;
        line_count++;
    }

    fclose(file);
}

// CSV yazma fonksiyonu
void write_csv(csv *csv_data, char *filename) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        perror("Dosya açılamadı");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < csv_data->n_lines; i++) {
        for (int j = 0; j < csv_data->matrix[i].n_columns; j++) {
            fprintf(file, "%.2f", csv_data->matrix[i].values[j]);
            if (j < csv_data->matrix[i].n_columns - 1) {
                fprintf(file, "%s", csv_data->sep);
            }
        }
        fprintf(file, "\n");
    }

    fclose(file);
}

// Ana fonksiyon
int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Kullanım: %s <giris_dosyasi> <cikis_dosyasi> [ayrac] [baslik_satir_sayisi]\n", argv[0]);
        return EXIT_FAILURE;
    }

    csv csv_data;
    csv_data.sep = (argc > 3) ? argv[3] : ",";
    csv_data.n_header = (argc > 4) ? atoi(argv[4]) : 0;

    read_csv(&csv_data, argv[1]);
    write_csv(&csv_data, argv[2]);

    // Dinamik olarak ayrılan belleği serbest bırak
    for (int i = 0; i < csv_data.n_lines; i++) {
        free(csv_data.matrix[i].values);
    }
    free(csv_data.matrix);

    return EXIT_SUCCESS;
}
