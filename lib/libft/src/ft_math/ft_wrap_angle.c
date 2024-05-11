

#include "libft.h"

double
ft_wrap_angle(double angle) {
    if (angle < 0.0) return (angle + 2.0 * PI);
    if (angle > 2.0 * PI) return (angle - 2.0 * PI);
    return (angle);
}
