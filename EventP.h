//
// Created by Aaron Fainman on 2022/01/02.
//

#ifndef DIFFERENTIALEQNS_EVENTP_H
#define DIFFERENTIALEQNS_EVENTP_H

#include "EventType.h"
#include "Window.h"
#include "Simulation.h"

#include <iostream>
using namespace std;

class EventP : public EventType {
public:
    EventP(Window& wind, Simulation& sim) : window{wind}, simulation{sim} {     }
    bool occurs(sf::Event& event) { if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::P) return true; return false;}
    void action() { simulation.pause();  };

private:
    Window& window;
    Simulation& simulation;

};

#endif //DIFFERENTIALEQNS_EVENTP_H
