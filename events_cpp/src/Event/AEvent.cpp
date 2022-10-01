/*!
** Experiments PROJECT, 2022
** @file AEvent.cpp
** File description:
** @brief
** @author
** [Arnaud Guerout](https://github.com/Guerout-Arnaud)
** @authors
**
*/


#include <iostream>
#include <cxxabi.h>

#include "AEvent.hpp"

namespace Event {


AEvent::AEvent()
{
    super();
}

AEvent::~AEvent()
{
}

void AEvent::execute()
{
    std::cout << "AEvent::execute()" << std::endl;
}

std::string AEvent::getClassName()
{
    return (_className);
}


void AEvent::super(void)
{
    int status;
    char *realname = abi::__cxa_demangle(typeid(*this).name(), 0, 0, &status);

    if (realname == NULL || status != 0) {
        std::string errorMessage = "Failed to demangle class name: " + std::string(typeid(*this).name()) + "!\n";
        errorMessage += "Status code : " + std::to_string(status) + "\n";

        switch (status)
        {
            case -1: // Info : std::bad_alloc more suitable in this case but no ctor takes a string
                errorMessage += "A memory allocation failiure occurred.\n";
                break;
            case -2:
                errorMessage += "mangled_name is not a valid name under the C++ ABI mangling rules.\n";
                break;
            case -3: // Info : std::invalid_argument more suitable in this case
                errorMessage += "One of the arguments is invalid.\n";
                break;
            default:
                errorMessage += "Unknown error!\n";
                break;
        }
        throw std::runtime_error(errorMessage);
    }

    _className = realname;
    free(realname);
}


}

