#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include "../header/main.h"

void foo(int x, int y) {
    printf("bar - %d \n", add(x, y));
};

int main() {
    char* hello = "hello world";
    char* hello_2 = malloc((strlen(hello)) * sizeof(char));
    printf("%s", hello);
    printf("\n");
    strcpy(hello_2, hello);
    printf("%s", hello_2);
    printf("\n");
    free(hello_2);

    int* arr = calloc(strlen(hello), sizeof(int));
    if (arr == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    int i = 0;
    int size = strlen(hello); // Size of the dynamically allocated array
    while (i < size) {
        printf("%d", arr[i]);
        i++;
    }
    free(arr); // Deallocate memory for arr

    printf("\n");
    printf("%d",add(1,2));
    printf("\n");
    printf("%d",add(1,2));
    printf("\n");
    printf("%d",add(1,2));

    printf("\n");
    printf("%d",add(1,2));
    printf("\n");
    int a = 2;
    int y = 4;
    foo(a,y);
    foo(a,y);
    return 0;
}