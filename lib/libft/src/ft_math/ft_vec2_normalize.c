

#include "libft.h"

t_vec2
ft_vec2_normalize(t_vec2 v) {
    double len;

    len = ft_vec2_length(v);
    if (len == 0.0) return ((t_vec2){ 0.0, 0.0 });
    v.x = v.x / len;
    v.y = v.y / len;
    return (v);
}
