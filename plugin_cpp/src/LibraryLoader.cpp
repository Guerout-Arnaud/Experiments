/*!
** Experiments PROJECT, 2022
** @file LibraryLoader.cpp
** File description:
** @brief LibraryLoader class implementation
** @author
** [Arnaud Guerout](https://github.com/Guerout-Arnaud)
** @authors
**
*/

extern "C" {
    #include <dlfcn.h>
}

#include <iostream>
#include <fstream>
#include <memory>
#include <functional>

#include "LibraryLoader.hpp"

LibraryLoader::LibraryLoader()
{
}

std::unique_ptr<void, std::function<void(void *)>> LibraryLoader::load(const std::string &filePath)
{
    std::cout << "load" << std::endl;

    assertValidFile(filePath);

    dlerror();

    std::unique_ptr<void, std::function<void(void *)>> handle(dlopen(filePath.c_str(), RTLD_NOW), LibraryLoader::unload);

    if (handle == nullptr) {
        std::cerr << "Error: " << dlerror() << std::endl;
        throw std::runtime_error(dlerror());
    }
    return (handle);
}

template <typename T>
std::unique_ptr<T, std::default_delete<T>> LibraryLoader::createInstance(std::unique_ptr<void, std::function<void(void *)>> handle)
{
    std::cout << "getInstance" << std::endl;

    if (handle == nullptr)
    {
        throw std::invalid_argument("handle is null");
    }

    dlerror();

    void *rawWrappedCtor = dlsym(handle.get(), "createInstance");

    if (rawWrappedCtor == nullptr)
    {
        throw std::runtime_error(dlerror());
    }

    std::function<std::unique_ptr<T>(std::unique_ptr<void, std::function<void(void *)>>)> warppedCtor = reinterpret_cast<std::unique_ptr<T> (*)(std::unique_ptr<void, std::function<void(void *)>>)>(rawWrappedCtor);

    return (warppedCtor(std::move(handle)));
}


#include "ICommand.hpp"
template std::unique_ptr<ICommand> LibraryLoader::createInstance(std::unique_ptr<void, std::function<void(void *)>> handle);


// #include "ACommand.hpp"
// template std::unique_ptr<ACommand> LibraryLoader::createInstance(std::unique_ptr<void, std::function<void(void *)>> handle);

// std::unique_ptr<ICommand> LibraryLoader::createInstance(std::unique_ptr<void, std::function<void(void *)>> handle)
// {
//     std::cout << "getInstance" << std::endl;

//     if (handle == nullptr)
//     {
//         throw std::invalid_argument("handle is null");
//     }

//     dlerror();

//     void *rawWrappedCtor = dlsym(handle.get(), "createInstance");

//     if (rawWrappedCtor == nullptr)
//     {
//         throw std::runtime_error(dlerror());
//     }

//     std::function<std::unique_ptr<T>(std::unique_ptr<void, std::function<void(void *)>>)> warppedCtor = reinterpret_cast<std::unique_ptr<T> (*)(std::unique_ptr<void, std::function<void(void *)>>)>(rawWrappedCtor);

//     return (warppedCtor(std::move(handle)));
// }


void LibraryLoader::unload(void *handle)
{
    if (handle == nullptr)
    {
        std::cerr << "handle is null" << std::endl;
        return;
    }

    dlerror();

    if (dlclose(handle) != 0)
    {
        std::cerr << dlerror() << std::endl;
    }

    std::cout << "unload" << std::endl;
}

void LibraryLoader::assertValidFile(const std::string &filePath)
{
    std::ifstream file;
    if (filePath.substr(filePath.find_last_of(".") + 1) != "so")
    {
        std::cerr << "Filename is: " << filePath << std::endl;
        std::cerr << "Filename extension is: " << filePath.substr(filePath.find_last_of(".") + 1) << std::endl;
        std::cerr << "Filename extension check is: " << (filePath.substr(filePath.find_last_of(".") + 1) == "so") << std::endl;

        throw std::invalid_argument("File is not a \".so\".");
    }

    file = std::ifstream(filePath);
    if (!file.good())
    {
        throw std::invalid_argument("File not found.");
    }
}