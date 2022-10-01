/*!
** Experiments PROJECT, 2022
** @file IListener.hpp
** File description:
** @brief
** @author
** [Arnaud Guerout](https://github.com/Guerout-Arnaud)
** @authors
**
*/

#ifndef ILISTENER_HPP_
    #define ILISTENER_HPP_

    #include "IEvent.hpp"

namespace Event {

    class IEventListener {
        public:
            virtual ~IEventListener() = default;

        protected:
            IEventListener() = default;
    };

}

#endif