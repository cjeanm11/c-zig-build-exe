#include "libft.h"
#include <fcntl.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE (1024)
#endif

static char*
cleanup_and_exit(int fd, t_string* str) {
    close(fd);
    ft_str_free(str);
    return NULL;
}

char*
ft_read_to_str(const char* file) {
    int fd = open(file, O_RDONLY);
    if (fd == -1) return NULL;

    t_string content;
    ft_str_new(&content, NULL);

    char buffer[BUFFER_SIZE];
    ssize_t bytes;

    while ((bytes = read(fd, buffer, BUFFER_SIZE)) > 0) {
        buffer[bytes] = '\0';
        if (!ft_str_append(&content, buffer)) {
            cleanup_and_exit(fd, &content);
            return NULL;
        }
    }

    if (bytes == -1) {
        cleanup_and_exit(fd, &content);
        return NULL;
    }

    close(fd);
    return ft_str_take(&content);
}
