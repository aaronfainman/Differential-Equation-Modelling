//
// Created by Aaron Fainman on 2022/01/02.
//

#include "Simulation.h"

Simulation::Simulation(double particleSize, ExternalState& externalState)
    : particle_size{particleSize}, num_particles{externalState.NUM_PARTICLES}, external_state{externalState}
{
    reset();
}

void Simulation::run()
{
    if(!isRunning) return;

    external_state.time += external_state.TIME_INCREMENT;
    updateParticles();
    updatePixels();
    removeAndReplace();
}

void Simulation::updateParticles(){
    for(auto& particle: particles)
        particle->calculateNextState();

    for(auto& particle: particles)
    {
        particle->update();
    }
}

void Simulation::updatePixels(){
    for(auto& pixel: pixels)
        pixel->updateState();


}

void Simulation::reset()
{
    for(auto i=0; i<particles.size(); i++) delete particles[i];
    for(auto i=0; i<pixels.size(); i++) delete pixels[i];
    particles.clear();
    pixels.clear();
    particlePlacement();
}


void Simulation::pause()
{
    isRunning = not isRunning;
}


void Simulation::particlePlacement( )
{
    srand(0);
    auto RMAX = (double) RAND_MAX;

    for(auto i=0; i<num_particles; i++)
    {
        auto start_x = 2*(rand()-0.5*RMAX)/RMAX*external_state.x_lim;
        auto start_y =  2*(rand()-0.5*RMAX)/RMAX*external_state.y_lim;
        particles.push_back(new Particle(external_state,particle_size, start_x, start_y, 0.0, 0.0));
        pixels.push_back(new DrawablePixel(*particles.back(), PARTICLE_SIZE_MULT, 1.0));
    }

}


void Simulation::removeAndReplace()
{
    auto n = particles.size();

    auto to_remove = vector<int>{};

    for(auto i=0; i<n; i++)
    {
        if( outOfFrame(particles[i]->getX(), particles[i]->getY()) )
            to_remove.push_back(i);
    }

    for(auto i=0; i<to_remove.size(); i++)
    {
        delete particles[to_remove[i]];
        delete pixels[to_remove[i]];
        auto x_start = (double) -external_state.x_lim;
        auto y_start = (double) -external_state.y_lim;
        switch(i%4)
        {
            case 0: //position along leftmost vertical
                y_start += rand()/((double)RAND_MAX)*2*external_state.y_lim;//external_state.y_lim/(1.0*to_remove.size())*i;
                break;
            case 1: //position along topmost horizontal
                x_start += rand()/((double)RAND_MAX)*2*external_state.x_lim;
                break;
            case 2: //position along rightmost vertical
                y_start += rand()/((double)RAND_MAX)*2*external_state.y_lim;
                x_start = external_state.x_lim;
                break;
            default: //position along bottom horizontal
                x_start += rand()/((double)RAND_MAX)*2*external_state.x_lim;
                y_start = external_state.y_lim;
        }
        particles[to_remove[i]] = new Particle(external_state, particle_size, x_start, y_start, 0,0);
        pixels[to_remove[i]] = new DrawablePixel(*particles[to_remove[i]], PARTICLE_SIZE_MULT, 1.0);
    }
}

bool Simulation::outOfFrame(double x_pos, double y_pos) const
{
    if(x_pos>external_state.x_lim) return true;
    if(x_pos<-external_state.x_lim) return true;
    if(y_pos>external_state.y_lim) return true;
    if(y_pos<-external_state.y_lim) return true;

    return false;
}