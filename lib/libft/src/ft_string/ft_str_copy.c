#include "libft.h"
#include <stdlib.h>

t_string*
ft_str_copy(t_string* dst, const char* src) {
    ft_str_clear(dst);
    return ft_str_append(dst, src);
}
