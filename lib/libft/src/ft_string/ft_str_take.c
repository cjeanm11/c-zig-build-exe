#include "libft.h"

char*
ft_str_take(t_string* str) {
    char* ret = str->data;
    str->data = NULL;
    ft_str_free(str);
    return ret;
}
