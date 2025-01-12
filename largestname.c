#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max_name_length 50

int str_len(char *s) {
    int l = 0;
    while (s[l] != '\0') {
        l++;
    }
    return l;
}

char *string_copy(char *dest, const char *src) {
    char *start = dest;
    while (*src != '\0') {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0';
    return start;
}

void find_lar_name(char ***names_matrix, int rows, int cols) {
    char *largest_name = (char *)malloc(max_name_length * sizeof(char));
    string_copy(largest_name, names_matrix[0][0]);

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (str_len(names_matrix[i][j]) > str_len(largest_name)) {
                string_copy(largest_name, names_matrix[i][j]);
            }
        }
    }

    printf("Largest Names:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (str_len(names_matrix[i][j]) == str_len(largest_name)) {
                printf("%s\n", names_matrix[i][j]);
            }
        }
    }

    free(largest_name);
}

int main() {
    int rows, cols;
    scanf("%d", &rows);
    scanf("%d", &cols);

    char ***names_matrix = (char ***)malloc(rows * sizeof(char **));
    for (int i = 0; i < rows; i++) {
        names_matrix[i] = (char **)malloc(cols * sizeof(char *));
        for (int j = 0; j < cols; j++) {
            names_matrix[i][j] = (char *)malloc(max_name_length * sizeof(char));
            scanf("%s", names_matrix[i][j]);
        }
    }

    find_lar_name(names_matrix, rows, cols);

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            free(names_matrix[i][j]);
        }
        free(names_matrix[i]);
    }
    free(names_matrix);

    return 0;
}
