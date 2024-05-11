#include "libft.h"

void
ft_dlstclear(t_dlist** lst, void (*del)(void*)) {
    if (!lst || !del) return;

    t_dlist* curr = *lst;
    t_dlist* next;

    while (curr) {
        next = curr->next;
        ft_dlstdelone(curr, del);
        curr = next;
    }

    *lst = NULL;
}
