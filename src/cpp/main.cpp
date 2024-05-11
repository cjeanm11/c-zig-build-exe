#include "./../../include/cpp/main.hpp"
#include "./../../include/cpp/example.hpp"
#include "./../../include/cpp/status.hpp"
#include <exception>
#include <functional>
#include <future>
#include <iostream>
#include <memory>
#include <mutex>
#include <string>
#include <thread>

namespace ex = example_namespace;

std::mutex dataMutex;

std::future<Status>
modifyExample(std::shared_ptr<ex::Example>& example) {
    return std::async(std::launch::async, [example]() -> Status {
        std::lock_guard<std::mutex> lock(dataMutex);
        try {
            example->set_name("Modified");
            return Status();
        } catch (const std::exception& e) {
            return StatusFromException(e);
        }
    });
}

std::future<Status>
observeExample(std::weak_ptr<ex::Example> weakExample) {
    return std::async(std::launch::async, [weakExample]() -> Status {
        if (auto sharedExample = weakExample.lock()) {
            try {
                sharedExample->DoSomething();
                return Status();
            } catch (const std::exception& e) {
                return StatusFromException(e);
            }
        } else {
            return Status(StatusCode::kNotFound, "Example object is no longer valid.");
        }
    });
}

int
main() {

    auto sharedExample = std::make_shared<ex::Example>("Original");

    std::future<Status> t1 = modifyExample(sharedExample);
    std::future<Status> t2 = observeExample(sharedExample);

    if (Status status = t1.get(); !status.ok()) {
        std::cerr << "Error in modifyExample: " << status << std::endl;
        return 1;
    }

    if (Status status = t2.get(); !status.ok()) {
        std::cerr << "Error in observeExample: " << status << std::endl;
        return 1;
    }

    std::cout << "Tasks completed successfully.\n";
    return 0;
}
