#ifndef STATUS_H_
#define STATUS_H_

#include <iostream>
#include <string>
#include <unordered_map>

enum class StatusCode {
    kOk = 0,
    kCancelled = 1,
    kUnknown = 2,
    kInvalidArgument = 3,
    kDeadlineExceeded = 4,
    kNotFound = 5,
    // ...
};

class Status {
public:
    Status()
        : code_(StatusCode::kOk) {
    }

    Status(StatusCode code, const std::string& msg = "")
        : code_(code),
          msg_(msg) {
    }

    bool
    ok() const {
        return code_ == StatusCode::kOk;
    }

    StatusCode
    code() const {
        return code_;
    }

    const std::string&
    message() const {
        return msg_;
    }

    std::string
    ToString() const {
        if (ok()) {
            return "OK";
        } else {
            return std::string(CodeAsString(code_)) + ": " + msg_;
        }
    }

    friend std::ostream&
    operator<<(std::ostream& os, const Status& status) {
        return os << status.ToString();
    }

    operator bool() const {
        return ok();
    }

private:
    static const char*
    CodeAsString(StatusCode code) {
        // Using a static map for potentially better performance and maintainability
        static const std::unordered_map<StatusCode, const char*> codeMap = {
            { StatusCode::kOk,               "OK"                },
            { StatusCode::kCancelled,        "CANCELLED"         },
            { StatusCode::kUnknown,          "UNKNOWN"           },
            { StatusCode::kInvalidArgument,  "INVALID_ARGUMENT"  },
            { StatusCode::kDeadlineExceeded, "DEADLINE_EXCEEDED" },
            { StatusCode::kNotFound,         "NOT_FOUND"         },
        };

        auto it = codeMap.find(code);
        return (it != codeMap.end()) ? it->second : "UNRECOGNIZED";
    }

    StatusCode code_;
    std::string msg_;
};

static Status
StatusFromException(const std::exception& e) {
    return Status(StatusCode::kUnknown, e.what());
}
#endif // STATUS_H_
