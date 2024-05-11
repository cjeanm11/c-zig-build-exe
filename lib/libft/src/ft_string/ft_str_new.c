#include "libft.h"
#include <stdlib.h>

t_string*
ft_str_new(t_string* dst, char* cstr) {
    dst->data = cstr;
    dst->len = (cstr) ? ft_strlen(cstr) : 0;
    dst->cap = dst->len + 1;
    return dst;
}
