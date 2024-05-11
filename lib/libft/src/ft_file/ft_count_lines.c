#include "libft.h"
#include <fcntl.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE (1024)
#endif

static ssize_t
count_newlines(const char* str) {
    ssize_t count = 0;
    const char* newline = str;
    while ((newline = ft_strchr(newline, '\n'))) {
        ++count;
        newline++;
    }
    return count;
}

ssize_t
ft_count_lines(const char* file) {
    int fd = open(file, O_RDONLY);
    if (fd == -1) return -1;

    ssize_t count = 1;
    char buf[BUFFER_SIZE + 1];
    ssize_t bytes;

    while ((bytes = read(fd, buf, BUFFER_SIZE)) > 0) {
        buf[bytes] = '\0';
        count += count_newlines(buf);
    }

    close(fd);
    return count;
}
