

#include "libft.h"
#include <stdlib.h>

char**
ft_strarr_dup(char* const* arr) {
    size_t i;
    char** dup;

    i = ft_strarr_size(arr);
    dup = malloc((i + 1) * sizeof(char*));
    if (!dup) return (NULL);
    i = 0;
    while (arr[i]) {
        dup[i] = ft_strdup(arr[i]);
        if (!dup[i]) {
            ft_strarr_free(dup);
            return (NULL);
        }
        ++i;
    }
    dup[i] = NULL;
    return (dup);
}
