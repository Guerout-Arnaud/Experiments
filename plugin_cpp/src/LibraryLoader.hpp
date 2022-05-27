/*!
** Experiments PROJECT, 2022
** @file LibraryLoader.hpp
** File description:
** @brief LibraryLoader class header
** @author
** [Arnaud Guerout](https://github.com/Guerout-Arnaud)
** @authors
**
*/

#ifndef LIBRARY_LOADER_HPP_
    #define LIBRARY_LOADER_HPP_

    #include <string>
    #include <unordered_map>
    #include <memory>
    #include <functional>

    class LibraryLoader {
        public:
            LibraryLoader(const std::string &libDirPath = "./" );
            ~LibraryLoader();
            void load(const std::string &libName);
            void unload(const std::string &libName);


            template <typename T>
            std::unique_ptr<T> createInstance(const std::string &libName)
            {
                if (libName.empty()) throw std::invalid_argument("libName is empty");

                auto it = _loadedLibraries.find(libName);

                if (it == _loadedLibraries.end()) throw std::invalid_argument(libName + " is not loaded.");

                dlerror();
                void *rawWrappedCtor = dlsym(it->second.get(), "createInstance");

                if (rawWrappedCtor == nullptr) throw std::runtime_error(dlerror());

                std::function<std::unique_ptr<T>(std::shared_ptr<void> &)> wrappedCtor = reinterpret_cast<std::unique_ptr<T> (*)(std::shared_ptr<void>)>(rawWrappedCtor);


                std::cout << "createInstance(" << libName << ", " << it->second << ")" << std::endl;
                std::unique_ptr<T> instance = wrappedCtor(it->second);
                return (instance);
            }

        protected:

        private:
            std::string _libDirPath;

            std::unordered_map<std::string, std::shared_ptr<void>> _loadedLibraries;

            static void assertValidFile(const std::string &filePath);
            void unload(void *handle);

    };

#endif