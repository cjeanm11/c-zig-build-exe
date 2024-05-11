

#include "libft.h"

void
ft_putnbr_fd(int64_t n, int fd) {
    ft_putnbr_base_fd(n, "0123456789", fd);
}
