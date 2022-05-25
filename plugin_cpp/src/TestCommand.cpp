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

    TestCommand *createInstanceTest(std::unique_ptr<void, std::function<void (void*)>> handle)
    {
        std::cout << "createInstanceTest" << std::endl;

        TestCommand *test = new TestCommand(std::move(handle));
        return (test);
    }

    std::unique_ptr<TestCommand> createInstance(std::unique_ptr<void, std::function<void (void*)>> handle)
    {
        std::cout << "createInstance" << std::endl;

        std::unique_ptr<TestCommand> instance(new TestCommand(std::move(handle)));

        return instance;
        // return  std::make_unique<TestCommand>(new TestCommand(std::move(handle)));
    }

}



TestCommand::TestCommand(std::unique_ptr<void, std::function<void (void*)>> handle) : ACommand(std::move(handle))
{
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