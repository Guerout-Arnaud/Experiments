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

#ifndef XEVENT_LISTENER_HPP_
    #define XEVENT_LISTENER_HPP_

    #include "IEventListener.hpp"

namespace Event {

    class ABEventListener : public IEventListener {
        public:
            ABEventListener();
            ~ABEventListener();

            bool onEventA(IEvent &event);
            bool onEventB(IEvent &event);
    };

    class CEventListener : public IEventListener {
        public:
            CEventListener();
            ~CEventListener();

            bool onEventC(IEvent &event);
    };

}

#endif