

#include "libft.h"
#include <stdlib.h>

char*
ft_substr(const char* s, size_t start, size_t len) {
    size_t strlen;
    size_t size;
    char* substr;

    strlen = ft_strlen(s);
    size = 1;
    if (strlen > start)
        size += ft_strnlen(s + start, len);
    else
        start = strlen;
    substr = malloc(size * sizeof(char));
    if (!substr) return (NULL);
    ft_strlcpy(substr, s + start, size * sizeof(char));
    return (substr);
}
