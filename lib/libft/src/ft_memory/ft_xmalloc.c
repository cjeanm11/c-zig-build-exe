

#include "libft.h"
#include <stdlib.h>

void*
ft_xmalloc(size_t size) {
    void* ptr;

    ptr = malloc(size);
    if (!ptr) {
        ft_putendl_fd("Out of memory", STDERR_FILENO);
        exit(EXIT_FAILURE);
    }
    return (ptr);
}
