#include "libft.h"
#include <stdlib.h>

void
ft_str_free(t_string* str) {
    if (str) {
        free(str->data);
        str->data = NULL;
        str->len = 0;
        str->cap = 0;
    }
}
