

#include "libft.h"

char*
ft_strtrim(const char* s, const char* set) {
    const char* end;

    while (*s && ft_strchr(set, *s)) ++s;
    end = s + ft_strlen(s) - 1;
    while (end > s && ft_strchr(set, *end)) --end;
    return (ft_substr(s, 0, (size_t)(end - s + 1)));
}
