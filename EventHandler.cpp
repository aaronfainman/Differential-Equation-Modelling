//
// Created by Aaron Fainman on 2022/01/02.
//

#include "EventHandler.h"

EventHandler::EventHandler(Window& wind, Simulation& sim)
    : window{wind}, simulation{sim}
{
    all_events.push_back(new EventClose{window, simulation});
    all_events.push_back(new EventP{window, simulation});
    all_events.push_back(new EventSpace{window, simulation});
}



void EventHandler::run()
{
    sf::Event event;

    window.pollEvent(event);

    for(auto event_type: all_events)
    {
        if(event_type->occurs(event)) event_type->action();
    }
//    while (window.pollEvent(event)) {
//        if (event.type == sf::Event::Closed )
//            window.close();
//        if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space)
//            cout << "Space" << endl;
//            resetSimulation(particles, pixels, window);
//        if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::P)
//            cout << "P" << endl;
//            pauseSimulation(window);
//    }
}