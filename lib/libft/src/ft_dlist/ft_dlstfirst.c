#include "libft.h"

t_dlist*
ft_dlstfirst(t_dlist* lst) {
    if (!lst) return NULL;

    while (lst->prev) lst = lst->prev;

    return lst;
}
