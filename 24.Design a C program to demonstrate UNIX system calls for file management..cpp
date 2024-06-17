#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

int main() {
    int fd; // File descriptor
    ssize_t bytes_written, bytes_read;
    char buffer[100];
    
    // Create a new file
    fd = creat("test.txt", S_IRUSR | S_IWUSR);
    if (fd == -1) {
        perror("creat");
        exit(EXIT_FAILURE);
    }
    
    // Write some data to the file
    bytes_written = write(fd, "Hello, UNIX!", 12);
    if (bytes_written == -1) {
        perror("write");
        exit(EXIT_FAILURE);
    }
    printf("Wrote %zd bytes to the file\n", bytes_written);
    
    // Close the file
    close(fd);
    
    // Open the file for reading
    fd = open("test.txt", O_RDONLY);
    if (fd == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }
    
    // Read data from the file
    bytes_read = read(fd, buffer, sizeof(buffer));
    if (bytes_read == -1) {
        perror("read");
        exit(EXIT_FAILURE);
    }
    printf("Read %zd bytes: %.*s\n", bytes_read, (int)bytes_read, buffer);
    
    // Close the file
    close(fd);
    
    return 0;
}

