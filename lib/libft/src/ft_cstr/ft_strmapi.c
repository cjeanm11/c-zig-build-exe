

#include "libft.h"
#include <stdlib.h>

char*
ft_strmapi(const char* s, char (*f)(uint32_t, char)) {
    uint32_t i;
    char* ret;

    ret = malloc((ft_strlen(s) + 1) * sizeof(char));
    if (!ret) return (NULL);
    i = 0;
    while (s[i]) {
        ret[i] = f(i, s[i]);
        ++i;
    }
    ret[i] = '\0';
    return (ret);
}
