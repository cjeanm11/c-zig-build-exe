

#include "libft.h"

char*
ft_strarr_last(char** arr) {
    size_t i;

    i = 0;
    while (arr[i] && arr[i + 1]) ++i;
    return (arr[i]);
}
