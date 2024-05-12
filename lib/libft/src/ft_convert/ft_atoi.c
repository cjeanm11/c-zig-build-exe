#include "libft.h"

static bool wrapped(int32_t n, int32_t old, int32_t sign) {
    if (sign > 0) {
        return n < old;
    } else {
        return n > old;
    }
}

int32_t ft_atoi(const char* str) {
    int32_t result = 0;
    int32_t sign = 1;
    int64_t old;

    while (ft_isspace(*str)) {
        ++str;
    }
    if (*str == '-') {
        sign = -1;
        ++str;
    } else if (*str == '+') {
        ++str;
    }
    while (ft_isdigit(*str)) {
        old = result;
        result = (result * 10) + ((*str - '0') * sign);
        if (wrapped(result, old, sign)) {
            return -1;
        }
        str++;
    }
    return result;
}
