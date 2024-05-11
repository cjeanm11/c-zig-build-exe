#include "libft.h"

int32_t
ft_atoi(const char* str) {
    int32_t result = 0;
    int32_t sign = 1;

    while (*str && ft_isspace(*str)) ++str;

    if (*str == '-') {
        sign = -1;
        ++str;
    } else if (*str == '+') {
        ++str;
    }

    while (*str && ft_isdigit(*str)) {
        int32_t digit = *str - '0';
        if ((result > INT32_MAX / 10 || (result == INT32_MAX / 10 && digit > INT32_MAX % 10)) && sign == 1)
            return INT32_MAX;
        else if ((result > (uint32_t)INT32_MAX / 10 ||
                  (result == (uint32_t)INT32_MAX / 10 && digit > (uint32_t)INT32_MAX % 10)) &&
                 sign == -1)
            return INT32_MIN;
        result = result * 10 + digit;
        ++str;
    }

    return result * sign;
}
