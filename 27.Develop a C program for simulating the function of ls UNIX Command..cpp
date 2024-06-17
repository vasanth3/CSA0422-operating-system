#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>

int main(int argc, char *argv[]) {
    // Pointer to directory
    DIR *dir;
    // Directory entry structure
    struct dirent *entry;
    // Stat structure to get info about file
    struct stat fileStat;

    // Check if user has provided a directory path
    if (argc < 2) {
        // Open current directory
        dir = opendir(".");
    } else {
        // Open specified directory
        dir = opendir(argv[1]);
    }

    // Check if directory is opened successfully
    if (dir == NULL) {
        perror("Error opening directory");
        return 1;
    }

    // Iterate through each entry in the directory
    while ((entry = readdir(dir)) != NULL) {
        // Get information about the file
        if (stat(entry->d_name, &fileStat) < 0) {
            perror("Error getting file stat");
            return 1;
        }

        // Print file name
        printf("%s\t", entry->d_name);

        // Check if file is a directory
        if (S_ISDIR(fileStat.st_mode)) {
            printf("(Directory)\n");
        } else {
            printf("(File)\n");
        }
    }

    // Close directory
    closedir(dir);

    return 0;
}

