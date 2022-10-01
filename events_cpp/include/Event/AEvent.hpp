/*!
** Experiments PROJECT, 2022
** @file AEvent.hpp
** File description:
** @brief
** @author
** [Arnaud Guerout](https://github.com/Guerout-Arnaud)
** @authors
**
*/

#ifndef AEVENT_HPP_
    #define AEVENT_HPP_

    #include <string>

    #include "IEvent.hpp"

namespace Event {
    class AEvent : public IEvent {
        public:
            AEvent();
            ~AEvent();

            virtual void execute() override;

            virtual std::string getClassName();

        protected:
            std::string _className;

            virtual void super(void) final;
    };

}


#endif