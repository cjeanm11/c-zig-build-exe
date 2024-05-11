

#include "libft.h"

double
ft_clampd(double v, double min, double max) {
    if (v < min) return (min);
    if (v > max) return (max);
    return (v);
}
