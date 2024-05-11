#include "../header/main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int foo(int x, int y) {
    printf("bar - %d \n", add(x, y));
    return add(x, y);
};

int main() {
    printf("hello world %d \n", foo(2, 3));
    return 0;
}