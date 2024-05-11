

#include "libft.h"

t_vec2
ft_vec2_mul(t_vec2 a, double b) {
    return ((t_vec2){ .x = a.x * b, .y = a.y * b });
}
