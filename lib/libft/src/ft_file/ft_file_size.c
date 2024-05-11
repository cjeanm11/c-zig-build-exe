#include "my_lib.h"
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE (1024)
#endif

ssize_t
get_file_size(const char* filename) {
    int file_descriptor = open(filename, O_RDONLY);
    if (file_descriptor == -1) {
        return -1; // Error opening file
    }

    ssize_t total_bytes = 0;
    char buffer[BUFFER_SIZE];
    ssize_t bytes_read;

    while ((bytes_read = read(file_descriptor, buffer, BUFFER_SIZE)) > 0) {
        total_bytes += bytes_read;
    }

    close(file_descriptor);
    return total_bytes;
}
