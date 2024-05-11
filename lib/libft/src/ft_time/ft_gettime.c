#include "libft.h"

int
ft_gettime(t_time* t) {
    return gettimeofday(&t->tp, NULL);
}
