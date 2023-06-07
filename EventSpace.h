//
// Created by Aaron Fainman on 2022/01/02.
//

#ifndef DIFFERENTIALEQNS_EVENTSPACE_H
#define DIFFERENTIALEQNS_EVENTSPACE_H


#include "EventType.h"
#include "Window.h"
#include "Simulation.h"

#include <iostream>
using namespace std;

class EventSpace : public EventType {
public:
    EventSpace(Window& wind, Simulation& sim) : window{wind}, simulation{sim} {     }
    bool occurs(sf::Event& event) { if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space) return true; return false;}
    void action() {  simulation.reset(); window.clear();  };

private:
    Window& window;
    Simulation& simulation;

};

#endif //DIFFERENTIALEQNS_EVENTSPACE_H
