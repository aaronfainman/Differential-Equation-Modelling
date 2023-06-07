//
// Created by Aaron Fainman on 2022/01/02.
//

#ifndef DIFFERENTIALEQNS_EVENTHANDLER_H
#define DIFFERENTIALEQNS_EVENTHANDLER_H

#include "Window.h"
#include "Simulation.h"
#include "SFML/Window.hpp"
#include <vector>
#include <iostream>
#include "EventType.h"
#include "EventClose.h"
#include "EventP.h"
#include "EventSpace.h"

using namespace std;

class EventHandler {

public:
    EventHandler(Window& wind, Simulation& sim);

    void run();


private:
    Window& window;
    Simulation& simulation;
    vector<EventType*> all_events;

};


#endif //DIFFERENTIALEQNS_EVENTHANDLER_H
