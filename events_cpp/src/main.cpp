#include <vector>
#include <functional>
#include <map>
#include <memory>

#include "XEventsListeners/XEventListener.hpp"
#include "XEvents/EventX.hpp"

class Software {
    public:
        Software() = default;
        ~Software() = default;

        template<typename T>
        bool registerListener(T &event, std::function<bool(Event::IEvent &)> listenerPtr, Event::Priority priority = Event::Priority::NORMAL) {
            _eventsListeners[event.getClassName()].insert(std::make_pair(priority, listenerPtr));
            return (true);
        }

        void fireEvent(Event::IEvent &event) {
            for (auto &listener : _eventsListeners[event.getClassName()]) {
                listener.second(event);
            }
        }

    private:
        std::unordered_map <
            std::string,
            std::multimap <
                Event::Priority,
                std::function <bool (Event::IEvent &)>
            >
        > _eventsListeners;
};


int main(void)
{
    Software software = Software();


    Event::ABEventListener eventListenerAB = Event::ABEventListener();

    Event::EventA tmpA; // herite de Ievent
    software.registerListener<Event::EventA> (
        tmpA,
        std::bind(
            &Event::ABEventListener::onEventA
            , &eventListenerAB
            , std::placeholders::_1
        )
    );

    Event::EventB tmpB; // herite de Ievent
    software.registerListener<Event::EventB> (
        tmpB,
        std::bind(
            &Event::ABEventListener::onEventB
            , &eventListenerAB
            , std::placeholders::_1
        )
    );


    Event::CEventListener eventListenerC = Event::CEventListener();

    Event::EventC tmpC; // herite de Ievent
    software.registerListener<Event::EventC> (
        tmpC,
        std::bind(
            &Event::CEventListener::onEventC
            , &eventListenerC
            , std::placeholders::_1
        )
    );

    Event::EventA eventA = Event::EventA(); // herite de Ievent
    Event::EventB eventB = Event::EventB(); // herite de Ievent
    Event::EventC eventC = Event::EventC(); // herite de Ievent


    software.fireEvent(eventA);
    software.fireEvent(eventB);
    software.fireEvent(eventC);

    return (0);
}