#include "../../include/cpp/example.hpp"

namespace example_namespace {

Example::Example(const std::string& name)
    : name_(name) {
}

Example::~Example() {
}

std::shared_ptr<Example>
CreateExample(const std::string& name) {
    return std::make_shared<Example>(name);
}

const std::string&
Example::name() const {
    return name_;
}

void
Example::set_name(const std::string& name) {
    name_ = name;
}

void
Example::DoSomething() const {
    std::cout << "Doing something with " << name_ << "\n";
}

} // namespace example_namespace