//
// Created by Aaron Fainman on 2022/01/02.
//

#ifndef DIFFERENTIALEQNS_EVENTTYPE_H
#define DIFFERENTIALEQNS_EVENTTYPE_H

#include <SFML/Window.hpp>
#include <iostream>

using namespace std;

class EventType {
public:
    virtual bool occurs(sf::Event& event) = 0;
    virtual void action() = 0;

};

#endif //DIFFERENTIALEQNS_EVENTTYPE_H
