#include <iostream>
#include <memory>
#include <functional>

#include "TestCommand.hpp"

// void createInstance(std::unique_ptr<void> &handle)
// {
//     std::cout << "createInstance" << std::endl;
// }

extern "C" {
    // void createInstance(std::unique_ptr<void> &handle)
    // {
    //     std::cout << "createInstance" << std::endl;
    // }
    // void createInstance(std::unique_ptr<void> &handle)
    // {
    //     std::cout << "createInstance" << std::endl;
    // }

    std::unique_ptr<TestCommand> createInstance(std::shared_ptr<void> &handle)
    {
        std::cout << "createInstance" << std::endl;

        std::unique_ptr<TestCommand> instance(new TestCommand(handle));

        return (instance);
    }

}

TestCommand::TestCommand(std::shared_ptr<void> &handle) : ACommand(handle)
{
    std::cout << "TestCommand::TestCommand()" << std::endl;
    _name = "TestCommand";
}

TestCommand::~TestCommand()
{
    std::cout << "~TestCommand()" << std::endl;
}

const bool TestCommand::execute(const std::string &ACommand, const std::string &rawArgs)
{
    std::cout << "TestCommand::execute()" << std::endl;
    return (true);
}