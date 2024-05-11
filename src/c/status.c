#include "../../include/c/status.h"

Status
StatusCreate(StatusCode code, const char* message) {
    Status status;
    status.code = code;
    status.message = message; // Directly store the message pointer
    return status;
}

bool
StatusOk(const Status* status) {
    return status->code == OK;
}

StatusCode
StatusCodeGet(const Status* status) {
    return status->code;
}

const char*
StatusGetMessage(const Status* status) {
    return status->message ? status->message : "Unknown error"; // Default message if NULL
}

// Helper function to convert StatusCode to string
const char*
CodeAsString(StatusCode code) {
    switch (code) {
        case OK:
            return "OK";
        case CANCELLED:
            return "CANCELLED";
        case UNKNOWN:
            return "UNKNOWN";
        case INVALID_ARGUMENT:
            return "INVALID_ARGUMENT";
        case DEADLINE_EXCEEDED:
            return "DEADLINE_EXCEEDED";
        case NOT_FOUND:
            return "NOT_FOUND";
        default:
            return "UNRECOGNIZED";
    }
}

void
StatusPrint(const Status* status, FILE* stream) {
    if (stream == NULL) {
        stream = stderr;
    }
    if (StatusOk(status)) {
        fprintf(stream, "OK\n");
    } else {
        fprintf(stream, "%s: %s\n", CodeAsString(status->code), StatusGetMessage(status));
    }
}
