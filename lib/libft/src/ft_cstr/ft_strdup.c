

#include "libft.h"
#include <stdlib.h>

char*
ft_strdup(const char* s) {
    size_t size;
    char* dup;

    size = ft_strlen(s) + 1;
    dup = malloc(size * sizeof(char));
    if (!dup) return (NULL);
    ft_memcpy(dup, s, size * sizeof(char));
    return (dup);
}
