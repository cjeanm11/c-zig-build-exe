

#include "libft.h"

static void
putunbr_r(uint64_t n, const char* base, uint64_t radix, int fd) {
    if (n / radix != 0) putunbr_r(n / radix, base, radix, fd);
    ft_putchar_fd(base[n % radix], fd);
}

void
ft_putunbr_base_fd(uint64_t n, const char* base, int fd) {
    putunbr_r(n, base, (uint64_t)ft_strlen(base), fd);
}
