//
// Created by Aaron Fainman on 2021/12/08.
//

#ifndef DIFFERENTIALEQNS_EXTERNALSTATE_H
#define DIFFERENTIALEQNS_EXTERNALSTATE_H

struct Point
{
    double x;
    double y;
    Point(double x_, double y_) : x{x_}, y{y_} { }
};

struct ExternalState
{
    ExternalState( ) { }

    ExternalState(ExternalState& obj) { time = obj.time; TIME_INCREMENT = obj.TIME_INCREMENT; }
    static double time;
    float TIME_INCREMENT = 1e-2;
    double x_lim;
    double y_lim;
    unsigned int NUM_PARTICLES = 15e3;
    Point attraction_point = Point(0,0);
    Point rejection_point = Point(0,0);
};

#endif //DIFFERENTIALEQNS_EXTERNALSTATE_H
