/*!
** Experiments PROJECT, 2022
** @file ACommand.cpp
** File description:
** @brief Command Abstract class
** @author
** [Arnaud Guerout](https://github.com/Guerout-Arnaud)
** @authors
**
*/

#include <iostream>
#include <memory>
// #include <regex>

#include "ACommand.hpp"

ACommand::ACommand(std::shared_ptr<void> &handle) : ICommand(), _handle(nullptr)
{
    std::cout << "ACommand::ACommand()" << std::endl;
    std::cout << "handle: " << handle << std::endl;
    _handle = handle;
    std::cout << "After handle" << std::endl;
    _name = "AbstractCommand";
    handle;
}

ACommand::~ACommand()
{
    std::cout << "~ACommand()" << std::endl;
}

const std::string &ACommand::getName() const
{
    return (_name);
}

const bool ACommand::execute(const std::string &ACommand, const std::string &rawArgs)
{
    std::cout << "AbstractCommand::execute()" << std::endl;
    return (true);
}
