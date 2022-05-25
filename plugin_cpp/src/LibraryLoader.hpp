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
    #include <memory>
    #include <functional>

    class LibraryLoader {
        public:
            static std::unique_ptr<void, std::function<void (void*)>>load(const std::string &filePath);

            template <typename T>
            static std::unique_ptr<T, std::default_delete<T>> createInstance(std::unique_ptr<void, std::function<void (void*)>> handle);

        protected:

        private:
            static void unload(void *handle);
            static void assertValidFile(const std::string &filePath);

            LibraryLoader();
    };

#endif