

#include "libft.h"

static void
putnbr_r(int64_t n, const char* base, int64_t radix, int fd) {

    if (n < 0 && n / radix == 0) ft_putchar_fd('-', fd);
    if (n / radix != 0) putnbr_r(n / radix, base, radix, fd);
    if (n < 0)
        ft_putchar_fd(base[(n % radix) * -1], fd);
    else
        ft_putchar_fd(base[n % radix], fd);
}

void
ft_putnbr_base_fd(int64_t n, const char* base, int fd) {
    putnbr_r(n, base, (int64_t)ft_strlen(base), fd);
}
