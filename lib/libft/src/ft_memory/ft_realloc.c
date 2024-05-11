

#include "libft.h"
#include <stdlib.h>

void*
ft_realloc(void* ptr, size_t oldsize, size_t size) {
    int8_t* newptr;

    if (!ptr) return (malloc(size));
    if (size == 0 || oldsize == 0) {
        free(ptr);
        return (NULL);
    }
    if (oldsize == size) return (ptr);
    newptr = malloc(size);
    if (!newptr) return (NULL);
    if (oldsize < size) size = oldsize;
    ft_memcpy(newptr, ptr, size);
    free(ptr);
    return (newptr);
}
