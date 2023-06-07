//
// Created by Aaron Fainman on 2021/12/08.
//

#include "Particle.h"

ExternalState Particle::external_state;

Particle::Particle(ExternalState& external_state_, double size, double start_x, double start_y, double start_x_1, double start_y_1)
    : internal_state{size,start_x, start_y, start_x_1, start_y_1},
    next_state(size,start_x, start_y, start_x_1, start_y_1),
    prev_state(size,start_x, start_y, start_x_1, start_y_1)
{
    external_state = external_state_;
}


Particle::Particle(Particle& obj)
    : internal_state{obj.internal_state}, next_state{obj.next_state}, prev_state{obj.prev_state}
{

}



void Particle::calculateNextState() {

    if(current_step != 0) return;

    internal_state = next_state;
    prev_state = next_state;

    auto x = internal_state.x;
    auto y = internal_state.y;
    auto t = external_state.time/steps_between_states;
    //rejection point
 /*   auto r_rej = sqrt( pow(internal_state.x - external_state.rejection_point.x,2) + pow(internal_state.y - external_state.rejection_point.y,2) );
    if(r_rej<1) r_rej=1;
    auto x_1_rej = (internal_state.x - external_state.rejection_point.x)/r_rej;
    auto y_1_rej = (internal_state.y - external_state.rejection_point.y)/r_rej;

    auto r_attr = 0.001*sqrt( pow(internal_state.x - external_state.attraction_point.x,2) + pow(internal_state.y - external_state.attraction_point.y,2) );
    if(r_attr<1) r_attr=1;
    auto x_1_attr = ( external_state.attraction_point.x-internal_state.x)*r_attr;
    auto y_1_attr = ( external_state.attraction_point.y-internal_state.y)*r_attr;*/

//    next_state.x = 5*sin( (internal_state.x)/(internal_state.y)*external_state.time+internal_state.y*external_state.time)+ internal_state.x;
//    next_state.y = 5*cos( (internal_state.y)/(internal_state.x)*external_state.time-0.003*internal_state.y)+ internal_state.y;;

/*  ----- lines through origin ------
    next_state.x = 5*sin(x/y*t+y*t-0.1*atan(x))+x;
    next_state.y = 5*cos(y/x*t-0.3*atan(y))+y;
FRAME_LIM_MULTIPLIER =1;
const double POSITION_X_MULTIPLIER = 0.9;
const double POSITION_Y_MULTIPLIER = 0.9;
 TIME_INCR = 1e-2;
    */

//    next_state.x = 5*cos(x/y*t+y*t-0.1*atan(x))+x  + 0.001*x_1_attr-0.001*x_1_rej;
//    next_state.y = 5*sin(y/x*t-0.3*atan(y))+y + 0.001*y_1_attr-0.001*y_1_rej;
//    next_state.x = (x+x*y)/100 -cos(y*x)+ x;
//    next_state.y = (y-x*y)/100 +sin(x*y) +y;


    //** swirls and trajectories (frame lim [5,5])
//    next_state.x = -y+cos(2*x)/1-0.05*x;
//    next_state.y = x+sin(2*y)/1-0.05*y;

    //whirlpools (frame lim [5,5])
//    next_state.x = -y+cos(2*x)/10-0.05*x;
//    next_state.y = x+sin(2*y)/10-0.05*y;

    //** explore next
//    next_state.x_1 = -y+cos(2*x)-0.05*x;
//    next_state.y_1 = x+sin(2*y)-0.05*y;
//

    //concentric circles
//    next_state.x_1 = -y/(x*x+y*y);
//    next_state.y_1 = x/(x*x+y*y);

    //flow past a circle
    next_state.x_1 = 0.5-0.5*(x*x-y*y)/(pow(x*x-y*y,2)+4*x*x*y*y);
    next_state.y_1 = -x*y/(pow(x*x-y*y,2)+4*x*x*y*y);

    //hammer shape
//    next_state.x_1 = -0.5*log(y*y);
//    next_state.y_1 = 0.5*log(x*x);

    next_state.x = next_state.x_1*external_state.TIME_INCREMENT + internal_state.x;
    next_state.y = next_state.y_1*external_state.TIME_INCREMENT + internal_state.y;


}
#include <iostream>
void Particle::update()
{
//    cout << current_step << ": (" << prev_state.x << "," << prev_state.y << ")";
//    cout << "-> (" << internal_state.x << "," << internal_state.y << ")";
//    cout << "-> (" << next_state.x << "," << next_state.y << ")" << endl;
//    cout << internal_state.x << "," << internal_state.y << endl;
    internal_state.x = (current_step+1)*(next_state.x - prev_state.x)/steps_between_states + prev_state.x;
    internal_state.y = (current_step+1)*(next_state.y - prev_state.y)/steps_between_states + prev_state.y;

    current_step = (current_step+1)%steps_between_states;
//    internal_state = next_state;
}

double Particle::getX() const {return internal_state.x;}

double Particle::getY() const { return internal_state.y;}

double Particle::getSize() const { return internal_state.size;}