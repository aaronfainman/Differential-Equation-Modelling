//
// Created by Aaron Fainman on 2022/01/02.
//

#ifndef DIFFERENTIALEQNS_EVENTCLOSE_H
#define DIFFERENTIALEQNS_EVENTCLOSE_H

#include "EventType.h"
#include "Window.h"
#include "Simulation.h"

class EventClose : public EventType {
public:
    EventClose(Window& wind, Simulation& sim) : window{wind}, simulation{sim} {     }
    bool occurs(sf::Event& event) { if(event.type == sf::Event::Closed) return true; return false;}
    void action() {  window.close();   };

private:
    Window& window;
    Simulation& simulation;

};

#endif //DIFFERENTIALEQNS_EVENTCLOSE_H
