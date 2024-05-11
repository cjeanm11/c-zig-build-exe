#include "libft.h"

double
ft_timediff(t_time t1, t_time t2) {
    double diff = (double)(t2.tp.tv_sec - t1.tp.tv_sec) + (double)(t2.tp.tv_usec - t1.tp.tv_usec) * 0.000001;
    return diff;
}
