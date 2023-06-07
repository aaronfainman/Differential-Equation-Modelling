//
// Created by Aaron Fainman on 2021/12/08.
//

#include "Window.h"

Window::Window(unsigned int size_x, unsigned int size_y, string title)
    : window(sf::VideoMode{ size_x,size_y}, title, sf::Style::Close)
{
    window.setFramerateLimit(framerate_limit);
}

void Window::clear()
{
    window.clear();
}

void Window::display()
{
    window.display();
}

void Window::draw(sf::Drawable& obj)
{
    window.draw(obj);
}

void Window::close() {
    window.close();
}

bool Window::isOpen() const {
    return window.isOpen();
}

void Window::setView(float x1, float y1, float x_size, float y_size)
{
    sf::View view;
    view.reset(sf::FloatRect(x1, y1, x_size, y_size));
    window.setView(view);
}

bool Window::pollEvent(sf::Event& event)
{
    return window.pollEvent(event);
}

