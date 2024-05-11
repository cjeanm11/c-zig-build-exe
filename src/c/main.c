#include "../../include/c/main.h"

int
main(int argc, char* argv[]) {
    char* file_contents = NULL;
    size_t file_size = 0;

    for (int i = 0; i < argc; i++) {
        printf("  %s\n", argv[i]);
    }
    printf("Hello, C-World! \n");

    Status status = StatusCreate(UNKNOWN, "Error handling example.");
    if (!StatusOk(&status)) {
        printf("Error: %s\n", StatusGetMessage(&status));
        return 1;
    }
    return 0;
}