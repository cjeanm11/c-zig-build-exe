#include "libft.h"

t_string*
ft_str_push(t_string* dst, char c) {
    char cstr[2] = { c, '\0' };
    return ft_str_append(dst, cstr);
}
