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

#ifndef EVENTX_HPP_
    #define EVENTX_HPP_

    #include "AEvent.hpp"

namespace Event {

    class EventA : public AEvent {
        public:
            EventA();
            ~EventA();

            virtual void execute() override;
    };

    class EventB : public AEvent {
        public:
            EventB();
            ~EventB();

            virtual void execute() override;
    };

    class EventC : public AEvent {
        public:
            EventC();
            ~EventC();

            virtual void execute() override;
    };

}

#endif