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
    if (!argv[1] || !argv[2]) {
        std::cout << "Usage: " << argv[0] << " path_to_lib_dir lib_name" << std::endl;
        return (-1);
    }


    std::cout << "Library folder: " << argv[1] << std::endl;
    LibraryLoader loader = LibraryLoader(argv[1]);
    std::cout << std::endl;

    std::cout << "Loading library: " << argv[2] << std::endl;
    loader.load(argv[2]);
    std::cout << std::endl;




    std::cout << "Creating instance of ICommand" << std::endl;
    std::unique_ptr<ICommand> instance = loader.createInstance<ICommand>(argv[2]);
    std::cout << std::endl;

    // // std::unique_ptr<ICommand> instance = LibraryLoader::createInstance<ICommand>(std::move(handle));

    std::cout << "Executing command" << std::endl;
    instance->execute("TestCommand", "test");
    std::cout << std::endl;

    std::cout << "Releasing instance of ICommand" << std::endl;
    instance.reset();
    std::cout << std::endl;

    std::cout << "Unloading library: " << argv[2] << std::endl;
    loader.unload(std::string(argv[2]));
    std::cout << std::endl;

    std::cout << "Done." << std::endl;

    return (0);
}