/*!
** Experiments PROJECT, 2022
** @file ACommand.hpp
** File description:
** @brief Command Abstact class header
** @author
** [Arnaud Guerout](https://github.com/Guerout-Arnaud)
** @authors
**
*/

#ifndef ACOMMAND_HPP_
    #define ACOMMAND_HPP_

    #include <string>
    #include <memory>
    #include <functional>

    #include "ICommand.hpp"

    class ACommand : public ICommand {
        public:
            ACommand(std::unique_ptr<void, std::function<void (void*)>> handle);
            virtual ~ACommand() override;

            const std::string &getName() const final;
            const std::unique_ptr<void, std::function<void (void*)>> &getHandle() const final;

            virtual const bool execute(const std::string &ACommand, const std::string &rawArgs) override;

        protected:
            std::string _name;

        private:
            std::unique_ptr<void, std::function<void (void*)>> _handle;
    };


#endif