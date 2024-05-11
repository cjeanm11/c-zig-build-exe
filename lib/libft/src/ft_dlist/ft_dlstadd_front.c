#include "libft.h"

void
ft_dlstadd_front(t_dlist** lst, t_dlist* new) {
    if (!lst || !new) return;

    if (*lst) {
        t_dlist* first = ft_dlstfirst(*lst);
        new->next = first;
        new->prev = NULL;
        first->prev = new;
    }

    *lst = new;
}
