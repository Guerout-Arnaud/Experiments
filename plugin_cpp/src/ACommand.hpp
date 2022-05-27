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
            ACommand(std::shared_ptr<void> &handle);
            virtual ~ACommand() override;

            const std::string &getName() const final;

            virtual const bool execute(const std::string &ACommand, const std::string &rawArgs) override;

        protected:
            std::string _name;

        private:
            std::shared_ptr<void> _handle;
    };


#endif