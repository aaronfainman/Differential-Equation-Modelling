//
// Created by Aaron Fainman on 2021/12/08.
//

#include "DrawablePixel.h"


DrawablePixel::DrawablePixel(const Particle& particle_, double size_mult, double pos_mult)
    : x_pos{particle_.getX()}, y_pos{particle_.getY()}, size{particle_.getSize()*size_mult}, size_multiplier{size_mult},
       pos_multiplier{pos_mult}, particle{particle_}
{
    circle.setFillColor(sf::Color::White);
    circle.setRadius(size);
    circle.setPosition(x_pos, y_pos);
}

//sf::Shape DrawablePixel::getDrawable()
//{
//    cout << particle.getX() << " " << particle.getY() << " " << particle.getSize() << endl;
//    return circle;
//}

void DrawablePixel::draw(Window& window)
{
    window.draw(circle);
}


void DrawablePixel::updateState()
{
    x_pos = particle.getX();//*pos_multiplier;
    y_pos = particle.getY();//*pos_multiplier;
    size = particle.getSize()*size_multiplier;

    circle.setRadius(size);
    circle.setPosition(x_pos, y_pos);
}
