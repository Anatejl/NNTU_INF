#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INITIAL_BUFFER_SIZE 128

// Function to read the file and store each line in a dynamically allocated array
char **read_file(const char *filename, int *line_count) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Failed to open file");
        exit(EXIT_FAILURE);
    }

    int count = 0;
    int buffer_size = INITIAL_BUFFER_SIZE;
    char buffer[buffer_size];
    char **lines = NULL;

    while (fgets(buffer, buffer_size, file) != NULL) {
        size_t len = strlen(buffer);
        // Remove newline character from the line if present
        if (buffer[len - 1] == '\n') {
            buffer[len - 1] = '\0';
            len--;
        }
        lines = realloc(lines, sizeof(char *) * (count + 1));
        if (lines == NULL) {
            perror("Failed to realloc memory");
            exit(EXIT_FAILURE);
        }
        lines[count] = malloc(len + 1);
        if (lines[count] == NULL) {
            perror("Failed to allocate memory for line");
            exit(EXIT_FAILURE);
        }
        strcpy(lines[count], buffer);
        count++;
    }

    fclose(file);

    *line_count = count;
    return lines;
}

int main() {
    const char *filename = "array_start_locations.txt";
    int line_count;
    char **lines = read_file(filename, &line_count);

    printf("Number of lines: %d\n", line_count);
    for (int i = 0; i < line_count; i++) {
        printf("Line %d: %s\n", i + 1, lines[i]);
        free(lines[i]); // Free each line
    }
    free(lines); // Free the array of pointers

    return 0;
}