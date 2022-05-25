#include <iostream>
#include <memory>
#include <functional>


#include <dlfcn.h>

#include "LibraryLoader.hpp"
#include "ICommand.hpp"
#include "ACommand.hpp"
#include "TestCommand.hpp"

int main(int argc, char **argv)
{
    if (!argv[1]) {
        std::cout << "Usage: " << argv[0] << " path_to_lib" << std::endl;
        return (-1);
    }

    std::cout << "Loading library: " << argv[1] << std::endl;

    std::unique_ptr<void, std::function<void (void*)>> handle = LibraryLoader::load(argv[1]);

    void *rawF = dlsym(handle.get(), "createInstanceTest");

    if (!rawF) {
        std::cout << "Error: " << dlerror() << std::endl;
        return (-1);
    }

    std::function<ACommand *(std::unique_ptr<void, std::function<void (void*)>>)> f = reinterpret_cast< ACommand *(*)(std::unique_ptr<void, std::function<void(void *)>>)>(rawF);
    // std::function<TestCommand *(std::unique_ptr<void, std::function<void(void *)>>)> warppedCtor =  reinterpret_cast<std::unique_ptr<T> (*)(std::unique_ptr<void, std::function<void(void *)>>)>(rawWrappedCtor);


    ACommand *test = f(std::move(nullptr));
    // ACommand *test = new ACommand(std::move(handle));

    if (!test) {
        std::cout << "Error: test is null." << std::endl;
        return (-1);
    } else {
        std::cout << "test is not null." << std::endl;
    }

    delete (test);

    return (0);


    // std::cout << "Creating instance of ICommand" << std::endl;

    // std::unique_ptr<ICommand> instance = LibraryLoader::createInstance<ICommand>(std::move(handle));
    // // LibraryLoader::createInstance<ACommand>(std::move(handle));

    // // std::unique_ptr<ICommand> instance = LibraryLoader::createInstance<ICommand>(std::move(handle));
    // instance->execute("TestCommand", "test");


    std::cout << "Done." << std::endl;

    return (0);
}