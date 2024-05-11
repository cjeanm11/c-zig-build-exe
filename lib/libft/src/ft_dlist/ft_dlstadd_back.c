#include "libft.h"

void
ft_dlstadd_back(t_dlist** lst, t_dlist* new) {
    if (!lst || !new) return;

    if (*lst) {
        t_dlist* last = ft_dlstlast(*lst);
        last->next = new;
        new->prev = last;
    } else {
        *lst = new;
    }
}
