

#include "libft.h"

int64_t
ft_clamp(int64_t v, int64_t min, int64_t max) {
    if (v < min) return (min);
    if (v > max) return (max);
    return (v);
}
