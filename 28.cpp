#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 256

void grep(FILE *file, const char *pattern) {
    char line[MAX_LINE_LENGTH];

    while (fgets(line, sizeof(line), file)) {
        if (strstr(line, pattern) != NULL) {
            printf("%s", line);
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s pattern [file1 file2 ...]\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *pattern = argv[1];
    FILE *file;

    if (argc == 2) {
        // Read from standard input
        grep(stdin, pattern);
    } else {
        // Read from files
        for (int i = 2; i < argc; i++) {
            file = fopen(argv[i], "r");
            if (file == NULL) {
                fprintf(stderr, "Error: Cannot open file '%s'\n", argv[i]);
                continue;
            }
            grep(file, pattern);
            fclose(file);
        }
    }

    return EXIT_SUCCESS;
}

