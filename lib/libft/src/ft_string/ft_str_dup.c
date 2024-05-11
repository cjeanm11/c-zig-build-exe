#include "libft.h"
#include <stdlib.h>

t_string*
ft_str_dup(t_string* dst, const char* cstr) {
    char* copy = ft_strdup(cstr);
    if (!copy) return false;
    ft_str_free(dst);
    dst->data = copy;
    dst->len = ft_strlen(copy);
    dst->cap = dst->len + 1;
    return dst;
}
