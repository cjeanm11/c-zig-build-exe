

#include "ft_hmap.h"
#include "libft.h"

void*
ft_hmap_find(t_hmap m, const char* key) {
    t_list* lst;
    t_pair* pair;

    lst = *get_hmap_buckets(m, key);
    while (lst) {
        pair = lst->content;
        if (ft_strcmp(key, pair->key) == 0) return (pair->value);
        ft_lstnext(&lst);
    }
    return (NULL);
}
