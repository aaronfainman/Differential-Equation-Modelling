//
// Created by Aaron Fainman on 2022/01/02.
//

#ifndef DIFFERENTIALEQNS_SIMULATION_H
#define DIFFERENTIALEQNS_SIMULATION_H

#include "Particle.h"
#include "DrawablePixel.h"
#include <vector>
#include "ExternalState.h"
#include <iterator>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <utility>

using namespace std;

const double POSITION_X_MULTIPLIER = 0.9;
const double POSITION_Y_MULTIPLIER = 0.9;
const double PARTICLE_SIZE_MULT = 1e-2;

using ParticleContainer = vector<Particle*>;
using ParticleIter = vector<Particle*>::iterator;

using PixelContainer = vector<DrawablePixel*>;
using PixelIter = vector<DrawablePixel*>::iterator;

class Simulation {
public:
    Simulation(double particleSize, ExternalState& externalState);

    void run();

    void reset();

    void pause();

    bool isUpdated() const { return isRunning;}

    vector<DrawablePixel*>::iterator pixelBegin() { return pixels.begin(); }
    pair<PixelIter, PixelIter> Pixels() { return make_pair(pixels.begin(), pixels.end()); }

private:
    bool isRunning = true;
    double particle_size;
    unsigned int num_particles;
    ExternalState& external_state;
    vector<Particle*> particles;
    vector<DrawablePixel*> pixels;

    void particlePlacement();

    void updateParticles();

    void updatePixels();

    void removeAndReplace();

    bool outOfFrame(double x_pos, double y_pos) const;


};


#endif //DIFFERENTIALEQNS_SIMULATION_H
