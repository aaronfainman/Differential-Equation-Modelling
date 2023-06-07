//
// Created by Aaron Fainman on 2021/12/08.
//

#ifndef DIFFERENTIALEQNS_WINDOW_H
#define DIFFERENTIALEQNS_WINDOW_H

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <string>

using namespace std;

class Window {
public:
    Window(unsigned int size_x=640, unsigned int size_y=480, string title="Window");

    void clear();

    void display();

    void draw(sf::Drawable& obj);

    void close();

    bool isOpen() const;

    bool pollEvent(sf::Event& event);

    void setView(float x1, float y1, float x_size, float y_size);


private:
    sf::RenderWindow window;

    const int framerate_limit = 100;

};


#endif //DIFFERENTIALEQNS_WINDOW_H
