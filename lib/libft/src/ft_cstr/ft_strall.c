

#include "libft.h"

bool
ft_strall(const char* s, bool (*f)(char)) {
    while (*s) {
        if (!f(*s)) return (false);
        ++s;
    }
    return (true);
}
