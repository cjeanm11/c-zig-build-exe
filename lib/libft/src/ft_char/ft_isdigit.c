#include <ctype.h>
#include <stdbool.h>

bool
ft_isdigit(char c) {
    if ((c >= '0' && c <= '9') || c == '-') {
        return true;
    } else {
        return false;
    }
}
