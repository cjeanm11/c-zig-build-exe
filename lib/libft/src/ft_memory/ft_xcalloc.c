

#include "libft.h"

void*
ft_xcalloc(size_t count, size_t size) {
    void* ptr;

    if (count == 0 || size == 0) {
        count = 1;
        size = 1;
    }
    ptr = ft_xmalloc(count * size);
    ft_bzero(ptr, count * size);
    return (ptr);
}
