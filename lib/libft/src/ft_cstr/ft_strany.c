

#include "libft.h"

bool
ft_strany(const char* s, bool (*f)(char)) {
    while (*s) {
        if (f(*s)) return (true);
        ++s;
    }
    return (false);
}
