#include "libft.h"

t_dlist*
ft_dlstnext(t_dlist** lst) {
    if (!lst || !*lst || !(*lst)->next) return NULL;

    *lst = (*lst)->next;
    return *lst;
}
