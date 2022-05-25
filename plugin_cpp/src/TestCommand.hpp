/*!
** Experiments PROJECT, 2022
** @file TestCommand.hpp
** File description:
** @brief TestCommand class header
** @author
** [Arnaud Guerout](https://github.com/Guerout-Arnaud)
** @authors
**
*/

#ifndef TEST_COMMAND_HPP_
    #define TEST_COMMAND_HPP_

    #include <string>
    #include <memory>
    #include <functional>

    #include "ACommand.hpp"

    class TestCommand : public ACommand {
        public:
            TestCommand(std::unique_ptr<void, std::function<void (void*)>> handle);
            ~TestCommand() final;

            const bool execute(const std::string &ACommand, const std::string &rawArgs) final;

        protected:

        private:
    };


#endif