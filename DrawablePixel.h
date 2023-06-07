//
// Created by Aaron Fainman on 2021/12/08.
//

#ifndef DIFFERENTIALEQNS_DRAWABLEPIXEL_H
#define DIFFERENTIALEQNS_DRAWABLEPIXEL_H

#include "Drawable.h"
#include <SFML/Graphics.hpp>
#include "Window.h"
#include "Particle.h"

using namespace std;

class DrawablePixel : public Drawable {

public:
    DrawablePixel(const Particle& particle, double size_mult = 1.0, double pos_mult=1.0);

//    sf::Shape getDrawable();
    void draw(Window& window);

    void updateState();

private:
    double size;
    double x_pos;
    double y_pos;
    double size_multiplier;
    double pos_multiplier;
    const Particle& particle;
    sf::CircleShape circle;

};


#endif //DIFFERENTIALEQNS_DRAWABLEPIXEL_H
