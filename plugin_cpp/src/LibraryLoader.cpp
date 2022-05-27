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

LibraryLoader::LibraryLoader(const std::string &path)
{
    if (path.empty())
        _libDirPath = "./";
    else if (path.back() != '/')
        _libDirPath = path + "/";
    else
        _libDirPath = path;

    _loadedLibraries = std::unordered_map<std::string, std::shared_ptr<void>>();
}

LibraryLoader::~LibraryLoader()
{
    for (auto &lib : _loadedLibraries)
        unload(lib.first);
}

void LibraryLoader::load(const std::string &libName)
{
    if (libName.empty())
    {
        throw std::invalid_argument("libName is empty");
    }

    std::string libPath = _libDirPath + "lib" + libName + ".so";

    assertValidFile(libPath);

    dlerror();

    std::shared_ptr<void> handle(dlopen(libPath.c_str(), RTLD_LAZY), [this](void *handle) {
        unload(handle);
    });

    if (handle == nullptr) {
        std::cerr << "Error: " << dlerror() << std::endl;
        throw std::runtime_error(dlerror());
    }

    std::cout << "Handle addr: " << handle.get() << " added" << std::endl;
    _loadedLibraries.insert({libName, handle});
    std::cout << "Library " << libName << " loaded" << std::endl;
}

void LibraryLoader::unload(const std::string &libName)
{
    if (libName.empty())
    {
        throw std::invalid_argument("libName is empty");
    }

    auto it = _loadedLibraries.find(libName);

    if (it == _loadedLibraries.end())
    {
        throw std::invalid_argument(libName + " is not loaded.");
    }

    if (it->second.use_count() > 1)
    {
        throw std::invalid_argument(libName + " is still in use.");
    }

    // dlerror();
    // if (dlclose(it->second.get()) != 0)
    // {
    //     throw std::runtime_error(dlerror());
    // }

    std::cout << "Handle addr: " << it->second.get() << std::endl;

    _loadedLibraries.erase(it);
    std::cout << "Library " << libName << " unloaded" << std::endl;

}


void LibraryLoader::unload(void *handle)
{
    if (handle == nullptr)
    {
        std::cerr << "handle is nullptr" << std::endl;
        return;
    }

    dlerror();
    if (dlclose(handle) != 0)
    {
        std::cerr << "Error: " << dlerror() << std::endl;
        return;
    }

    std::cout << "Library unloaded" << std::endl;

}

// template <typename T>
// std::unique_ptr<T> LibraryLoader::createInstance(const std::string &libName)



// #include "ICommand.hpp"
// template std::unique_ptr<ICommand> LibraryLoader::createInstance(std::unique_ptr<void, std::function<void(void *)>> handle);


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