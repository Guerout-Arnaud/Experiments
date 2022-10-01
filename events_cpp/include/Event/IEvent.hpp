/*!
** Experiments PROJECT, 2022
** @file IEvent.hpp
** File description:
** @brief
** @author
** [Arnaud Guerout](https://github.com/Guerout-Arnaud)
** @authors
**
*/

#ifndef IEVENT_HPP_
    #define IEVENT_HPP_

namespace Event {

    enum class Priority {
        LOWEST = 1,
        LOW = 2,
        NORMAL = 3,
        HIGH = 4,
        HIGHEST = 5,
        MONITOR = 6,
    };

    class IEvent {
        public:
            virtual ~IEvent () = default;

            virtual void execute() = 0;
            virtual std::string getClassName() = 0;

        protected:
            IEvent() = default;
            virtual void super() = 0;
    };

}


#endif