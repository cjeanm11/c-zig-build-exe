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

namespace ex = internal::example_namespace;

std::mutex dataMutex;

struct SharedData {
    std::mutex m;
    int value = 0;
};

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

    std::shared_ptr<SharedData> data = std::make_shared<SharedData>();
    auto increment = [data]() {
        for (int i = 0; i < 100000; ++i) {
            std::lock_guard<std::mutex> lock(data->m);
            ++data->value;
        }
    };
    std::thread t3(increment);
    std::thread t4(increment);
    t3.join();
    t4.join();

    std::cout << "Final value: " << data->value << std::endl;
    return 0;
}