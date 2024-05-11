

#include "libft.h"
#include <math.h>

double
ft_vec2_dist(t_vec2 a, t_vec2 b) {
    double dist_a;
    double dist_b;

    dist_a = b.x - a.x;
    dist_b = b.y - a.y;
    return (sqrt(dist_a * dist_a + dist_b * dist_b));
}
