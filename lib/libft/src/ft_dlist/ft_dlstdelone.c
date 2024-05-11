#include "libft.h"
#include <stdlib.h>

void
ft_dlstdelone(t_dlist* lst, void (*del)(void*)) {
    if (!lst || !del) return;

    del(lst->content);
    free(lst);
}
