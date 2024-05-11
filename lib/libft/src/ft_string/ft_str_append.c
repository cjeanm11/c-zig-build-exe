#include "libft.h"
#include <limits.h>
#include <stdlib.h>

static bool
grow_buffer(t_string* str, size_t newsize) {
    size_t nextcap = (str->cap > LONG_MAX / 2) ? LONG_MAX : str->cap * 2;
    if (newsize < nextcap) newsize = nextcap;
    char* buf = (!str->data) ? malloc(newsize * sizeof(char))
                             : ft_realloc(str->data, str->cap * sizeof(char), newsize * sizeof(char));
    if (!buf) return false;
    str->data = buf;
    str->cap = newsize;
    return true;
}

t_string*
ft_str_append(t_string* dst, const char* src) {
    size_t src_len = ft_strlen(src);
    if (dst->cap - dst->len <= src_len) {
        if (!grow_buffer(dst, src_len + dst->len + 1)) return NULL;
    }
    ft_strlcat(dst->data, src, dst->cap);
    dst->len += src_len;
    return dst;
}
