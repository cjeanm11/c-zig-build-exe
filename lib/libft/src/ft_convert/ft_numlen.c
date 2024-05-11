#include "libft.h"

size_t
ft_numlen(int64_t n, int64_t radix) {
    size_t len = 1;

    while (n /= radix) ++len;
    return len;
}
