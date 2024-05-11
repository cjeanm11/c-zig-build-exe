

#include "libft.h"
#include <math.h>

t_vec2
ft_vec2_unit(double angle) {
    return ((t_vec2){ .x = cos(angle), .y = sin(angle) });
}
