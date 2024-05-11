#include "libft.h"

t_string*
ft_str_trim(t_string* dst, const char* str, const char* set) {
    char* trim = ft_strtrim(str, set);
    if (!trim) return NULL;
    return ft_str_new(dst, trim);
}
