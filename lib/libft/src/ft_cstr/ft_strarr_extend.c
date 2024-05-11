

#include "libft.h"
#include <stdlib.h>

char**
ft_strarr_extend(char** arr, char* back_str) {
    size_t i;
    char** new;

    i = ft_strarr_size(arr);
    new = malloc((i + 2) * sizeof(char*));
    if (!new) return (NULL);
    i = 0;
    while (arr[i]) {
        new[i] = arr[i];
        arr[i] = NULL;
        ++i;
    }
    new[i++] = back_str;
    new[i] = NULL;
    ft_strarr_free(arr);
    return (new);
}
