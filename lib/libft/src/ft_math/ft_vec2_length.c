

#include "libft.h"
#include <math.h>

double
ft_vec2_length(t_vec2 v) {
    return (sqrt(v.x * v.x + v.y * v.y));
}
