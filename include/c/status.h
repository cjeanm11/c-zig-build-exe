#ifndef STATUS_H
#define STATUS_H

#include <stdbool.h>
#include <stdio.h>

// Error codes
typedef enum {
    OK = 0,
    CANCELLED = 1,
    UNKNOWN = 2,
    INVALID_ARGUMENT = 3,
    DEADLINE_EXCEEDED = 4,
    NOT_FOUND = 5,
    // ...
} StatusCode;

typedef struct {
    StatusCode code;
    const char* message;
} Status;

Status
StatusCreate(StatusCode code, const char* message);

bool
StatusOk(const Status* status);

StatusCode
StatusCodeGet(const Status* status);

const char*
StatusGetMessage(const Status* status);

void
StatusPrint(const Status* status, FILE* stream);

#endif // STATUS_H
