#include "libft.h"

char*
ft_ultoa(uint64_t n) {
    return ft_ultoa_base(n, "0123456789");
}
