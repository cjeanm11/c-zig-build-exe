#include "libft.h"

static void
ft_ntoa_base(char* b, uint64_t n, size_t len, const char* base) {
    uint64_t radix = (uint64_t)ft_strlen(base);

    while (len > 0) {
        b[--len] = base[n % radix];
        n /= radix;
    }
}

char*
ft_ultoa_base(uint64_t n, const char* base) {
    size_t len = ft_unumlen(n, ft_strlen(base));
    char* ret = ft_calloc(len + 1, sizeof(char));

    if (!ret) return NULL;

    ft_ntoa_base(ret, n, len, base);
    return ret;
}
