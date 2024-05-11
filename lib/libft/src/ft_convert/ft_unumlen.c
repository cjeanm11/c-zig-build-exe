#include "libft.h"

size_t
ft_unumlen(uint64_t n, uint64_t radix) {
    size_t len = 1;

    while (n /= radix) ++len;
    return len;
}
