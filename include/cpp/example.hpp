#ifndef EXAMPLE_H_
#define EXAMPLE_H_

#include <iostream>
#include <memory>
#include <string>

namespace example_namespace {

class Example {
public:
    explicit Example(const std::string& name);
    ~Example();

    const std::string&
    name() const;

    void
    set_name(const std::string& name);

    void
    DoSomething() const;

private:
    std::string name_;
    Example(const Example&) = delete;
    Example&
    operator=(const Example&) = delete;
};

} // namespace example_namespace

#endif // EXAMPLE_H_