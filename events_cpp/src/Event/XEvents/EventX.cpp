/*!
** Experiments PROJECT, 2022
** @file EventX.hpp
** File description:
** @brief
** @author
** [Arnaud Guerout](https://github.com/Guerout-Arnaud)
** @authors
**
*/

#include <iostream>

#include "XEvents/EventX.hpp"

namespace Event {

/* Event A */
EventA::EventA ()
{
    super();
}

EventA::~EventA ()
{
}

void EventA::execute()
{
    std::cout << "EventA::execute()" << std::endl;
}

/* Event B */
EventB::EventB ()
{
    super();
}

EventB::~EventB ()
{
}

void EventB::execute()
{
    std::cout << "EventB::execute()" << std::endl;
}


/* Event C */
EventC::EventC ()
{
    super();
}

EventC::~EventC ()
{
}

void EventC::execute()
{
    std::cout << "EventC::execute()" << std::endl;
}

}