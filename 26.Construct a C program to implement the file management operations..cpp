#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fp; // File pointer
    char filename[] = "example.txt"; // File name

    // Writing to a file
    fp = fopen(filename, "w"); // Open file for writing
    if (fp == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }
    fprintf(fp, "Hello, this is a test file!\n");
    fclose(fp); // Close file

    // Reading from a file
    char buffer[100];
    fp = fopen(filename, "r"); // Open file for reading
    if (fp == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }
    fgets(buffer, sizeof(buffer), fp); // Read file contents into buffer
    printf("File content: %s", buffer);
    fclose(fp); // Close file

    return 0;
}

