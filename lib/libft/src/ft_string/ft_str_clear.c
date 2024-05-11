#include "libft.h"

void
ft_str_clear(t_string* str) {
    str->data[0] = '\0';
    str->len = 0;
}
