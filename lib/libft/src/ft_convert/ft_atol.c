#include "libft.h"

int64_t
ft_atol(const char* str) {
    int64_t result = 0;
    int64_t sign = 1;

    while (*str && ft_isspace(*str)) ++str;

    if (*str == '-') {
        sign = -1;
        ++str;
    } else if (*str == '+') {
        ++str;
    }

    while (*str && ft_isdigit(*str)) {
        int64_t digit = *str - '0';
        int64_t old = result;
        result = result * 10 + digit * sign;
        if ((sign > 0 && result < old) || (sign < 0 && result > old)) return -1;
        ++str;
    }

    return result;
}
