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
#include <regex>

#include "ACommand.hpp"

ACommand::ACommand(std::unique_ptr<void, std::function<void (void*)>> handle)
{
    _handle = std::move(handle);
    _name = "AbstractCommand";
}

ACommand::~ACommand()
{
    std::cout << "~ACommand()" << std::endl;
}

const std::string &ACommand::getName() const
{
    return (_name);
}


const std::unique_ptr<void, std::function<void (void*)>> &ACommand::getHandle() const
{
    return (_handle);
}

const bool ACommand::execute(const std::string &ACommand, const std::string &rawArgs)
{
    std::cout << "AbstractCommand::execute()" << std::endl;
    return (true);
}
