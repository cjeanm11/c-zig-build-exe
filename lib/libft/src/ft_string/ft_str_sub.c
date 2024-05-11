#include "libft.h"

t_string*
ft_str_sub(t_string* dst, const char* str, size_t index, size_t len) {
    char* sub = ft_substr(str, index, len);
    if (!sub) return NULL;
    return ft_str_new(dst, sub);
}
