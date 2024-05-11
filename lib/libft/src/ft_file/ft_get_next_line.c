#include "libft.h"
#include <limits.h>
#include <stdlib.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE (1024)
#endif

#ifndef OPEN_MAX
#define OPEN_MAX (256)
#endif

static void
free_and_set(char** ptr, char* value) {
    free(*ptr);
    *ptr = value;
}

static int32_t
read_file(char** file_buffer, int fd) {
    char read_buffer[BUFFER_SIZE + 1];
    ssize_t bytes;

    bytes = read(fd, read_buffer, BUFFER_SIZE);
    if (bytes == -1) return -1;
    read_buffer[bytes] = '\0';
    *file_buffer = ft_strjoin(*file_buffer, read_buffer);
    if (!*file_buffer) return -1;
    if (bytes < BUFFER_SIZE) return 0;
    return 1;
}

static int32_t
get_line(char** buffer, char** line) {
    char* newline = ft_strchr(*buffer, '\n');
    if (!newline)
        *line = ft_strdup(*buffer);
    else
        *line = ft_substr(*buffer, 0, newline - *buffer);
    if (!*line) return -1;
    if (!newline) {
        free_and_set(buffer, NULL);
        return 0;
    } else {
        char* tmp = ft_substr(*buffer, ft_strlen(*line) + 1, BUFFER_SIZE);
        if (!tmp) return -1;
        free_and_set(buffer, tmp);
        return 1;
    }
}

int
ft_get_next_line(int fd, char** line) {
    static char* buffer[OPEN_MAX] = { NULL };
    if (!line) free_and_set(&buffer[fd], NULL);
    if (fd < 0 || fd >= OPEN_MAX || !line) return -1;
    if (!buffer[fd]) buffer[fd] = ft_strdup("");
    int code = 1;
    while (!ft_strchr(buffer[fd], '\n')) {
        code = read_file(&buffer[fd], fd);
        if (code < 1) break;
    }
    if (code == -1) {
        free_and_set(&buffer[fd], NULL);
        return -1;
    }
    return get_line(&buffer[fd], line);
}
