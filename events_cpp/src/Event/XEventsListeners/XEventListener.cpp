/*!
** Experiments PROJECT, 2022
** @file XEventListener.hpp
** File description:
** @brief
** @author
** [Arnaud Guerout](https://github.com/Guerout-Arnaud)
** @authors
**
*/

#include <iostream>

#include "XEventsListeners/XEventListener.hpp"

namespace Event {

/* ABEventListener */
ABEventListener::ABEventListener()
{
}

ABEventListener::~ABEventListener()
{
}

bool ABEventListener::onEventA(IEvent &event)
{
    std::cout << "ABEventAListener::onEventC()" << std::endl;
    event.execute();
    return (true);
}

bool ABEventListener::onEventB(IEvent &event)
{
    std::cout << "ABEventAListener::onEventB()" << std::endl;
    event.execute();
    return (true);
}


/* CEventListener */
CEventListener::CEventListener()
{
}

CEventListener::~CEventListener()
{
}

bool CEventListener::onEventC(IEvent &event)
{
    std::cout << "CEventAListener::onEventC()" << std::endl;
    event.execute();
    return (true);
}

}