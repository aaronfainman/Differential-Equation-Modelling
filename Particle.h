//
// Created by Aaron Fainman on 2021/12/08.
//

#ifndef DIFFERENTIALEQNS_PARTICLE_H
#define DIFFERENTIALEQNS_PARTICLE_H
#include "ExternalState.h"
#include "InternalState.h"
#include <cmath>

using namespace std;

class Particle {
public:
    Particle();

    Particle(ExternalState& externalState, double size, double start_x, double start_y, double start_x_1, double start_y_1);

    Particle(Particle& obj);

    void calculateNextState();

    void update();

    double getX() const;

    double getY() const;

    double getSize() const;

private:
    InternalState internal_state;
    InternalState next_state;
    InternalState prev_state;

    const int steps_between_states = 10;
    int current_step = 0;

    static ExternalState external_state;
};


#endif //DIFFERENTIALEQNS_PARTICLE_H
