/*!
** Experiments PROJECT, 2022
** @file ICommand.hpp
** File description:
** @brief Command interface
** @author
** [Arnaud Guerout](https://github.com/Guerout-Arnaud)
** @authors
**
*/

#ifndef ICOMMAND_HPP_
    #define ICOMMAND_HPP_

    #include <memory>

        class ICommand {
            public:
                virtual ~ICommand() = default;

                virtual const std::string &getName() const = 0;
                virtual const std::unique_ptr<void, std::function<void (void*)>> &getHandle() const = 0;
                virtual const bool execute(const std::string &command, const std::string &rawArgs) = 0;

            protected:
                ICommand() = default;

            private:

        };

#endif