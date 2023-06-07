
#include <string>
#include "Window.h"
#include "ExternalState.h"
#include "Particle.h"
#include "DrawablePixel.h"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

#include <chrono>
#include <thread>


#include "EventHandler.h"
#include "Simulation.h"

#include <cmath>

using namespace std;

void pixelPlacement(vector<Particle*>& particles, vector<DrawablePixel*>& pixels, unsigned int n);

void updateWindow(Window& window, Simulation& simulation);


const double FRAME_LIM_MULTIPLIER =1;
const double WINDOW_X = 2400;
const double WINDOW_Y = 1500;
double PARTICLE_SIZE = 1;

int main()
{

    Window window(WINDOW_X, WINDOW_Y, "DifferentialEqs");

    ExternalState external_state;
    external_state.NUM_PARTICLES = 3e3;
    external_state.TIME_INCREMENT = 5e-1;
    external_state.x_lim = 5;
    external_state.y_lim = WINDOW_Y/WINDOW_X*external_state.x_lim;


    PARTICLE_SIZE = 0.1*sqrt(external_state.x_lim*external_state.y_lim)+0.5;// external_state.x_lim*external_state.y_lim/25;
//    PARTICLE_SIZE = 1;
    window.setView(-external_state.x_lim,-external_state.y_lim,2*external_state.x_lim,2*external_state.y_lim);

    Simulation simulation(PARTICLE_SIZE, external_state);

    EventHandler event_handler(window, simulation);

    while (window.isOpen())
    {
        simulation.run();

        event_handler.run();

        if(simulation.isUpdated()) {
            updateWindow(window, simulation);
        }

//        this_thread::sleep_for(chrono::milliseconds(500));

    }

}




void updateWindow(Window& window, Simulation& simulation)
{
//    window.clear();
    auto iters = simulation.Pixels();
    auto iter = iters.first;

    while(iter != iters.second)
    {
        (*iter)->draw(window);
        ++iter;
    }
    window.display();

}




//void pauseSimulation(Window& window)
//{
//    sf::Event event;
//    window.pollEvent(event);
//    while (event.type != sf::Event::KeyPressed) {
//        window.pollEvent(event);
//    }
//
//}

//void resetSimulation(vector<Particle*>& particles, vector<DrawablePixel*>& pixels, Window& window)
//{
//    for(auto& part: particles) delete part;
//    for(auto& pix: pixels) delete pix;
//    particles.clear();
//    pixels.clear();
//
//    pixelPlacement(particles, pixels, num_particles);
//    updateWindow(window, pixels);
//
//    external_state.time = 0;
//}

//void AttractionPoint(vector<Particle*>& particles)
//{
//
//    auto max_x = 0.0;
//    auto max_y = 0.0;
//    auto min_x = 0.0;
//    auto min_y = 0.0;
//    for(auto& particle:particles)
//    {
//        max_x = max_x>particle->getX() ? max_x : particle->getX();
//        max_y = max_y>particle->getY() ? max_y : particle->getY();
//        min_x = min_x<particle->getX() ? min_x : particle->getX();
//        min_y = min_y<particle->getY() ? min_y : particle->getY();
//    }
//
//    auto num_bins = 10;
//    auto x_incr = (max_x-min_x)/num_bins;
//    auto y_incr = (max_y-min_y)/num_bins;
//    auto x_bins = vector<int>{};
//    auto y_bins = vector<int>{};
//
//    for(auto i=min_x; i<max_x; i+=x_incr) x_bins.push_back(i);
//    for(auto i=min_y; i<max_y; i+=y_incr) y_bins.push_back(i);
//
//    for(auto& particle:particles)
//    {
//        auto x = (int) floor((particle->getX() - min_x)/(x_incr));
//        if(x>=num_bins) x=num_bins-1;
//        if(x<0) x=0;
//        ++x_bins[x];
//        auto y = (int) floor((particle->getY() - min_y)/(y_incr));
//        if(y>=num_bins) y=num_bins-1;
//        if(y<0) y=0;
//        ++y_bins[y];
//    }
//
//    auto mode_x_idx = 0;
//    for(auto i=0; i<x_bins.size(); i++)
//        if(x_bins[i] > x_bins[mode_x_idx]) mode_x_idx = i;
//    auto mode_y_idx = 0;
//    for(auto i=0; i<y_bins.size(); i++)
//        if(y_bins[i] > y_bins[mode_x_idx]) mode_y_idx = i;
//    auto min_mode_x_idx = 0;
//    for(auto i=0; i<x_bins.size(); i++)
//        if(x_bins[i] < x_bins[mode_x_idx]) min_mode_x_idx = i;
//    auto min_mode_y_idx = 0;
//    for(auto i=0; i<y_bins.size(); i++)
//        if(y_bins[i] < y_bins[mode_x_idx]) min_mode_y_idx = i;
//
//
////    for(auto i: x_bins) cout << i << ","; cout << endl;
////    for(auto i: y_bins) cout << i << ","; cout << endl;
////    cout <<min_x << " " << min_y << endl <<max_x << " " << max_y << endl << mode_x_idx << " " << mode_y_idx <<endl<< endl;
//    auto mode_x = min_x + mode_x_idx*x_incr;
//    auto mode_y = min_y + mode_y_idx*y_incr;
//    auto min_mode_x = min_x + min_mode_x_idx*x_incr;
//    auto min_mode_y = min_y + min_mode_y_idx*y_incr;
//    external_state.rejection_point = Point{mode_x*1.0, mode_y*1.0};
//    external_state.attraction_point = Point{min_mode_x*1.0, min_mode_y*1.0};
//}
//
//void RejectionPoint(vector<Particle*>& particles)
//{
//    auto avg_x = 0.0;
//    auto avg_y = 0.0;
//    for(auto& particle:particles)
//    {
//        avg_x += particle->getX();
//        avg_y += particle->getY();
//    }
//    avg_x = avg_x/particles.size();
//    avg_y = avg_y/particles.size();
//
//    external_state.rejection_point = Point{avg_x, avg_y};
//}
//
//void pixelPlacement(vector<Particle*>& particles, vector<DrawablePixel*>& pixels, unsigned int n)
//{
//    srand(0);
//
//    auto RMAX = (double) RAND_MAX;
//
//    for(auto i=0; i<(int) sqrt(n); i++)
//    {
//        for(auto j=0; j<(int) sqrt(n); j++){
//            particles.push_back(new Particle(external_state, PARTICLE_SIZE, (rand()-0.5*RMAX)*WINDOW_X*POSITION_X_MULTIPLIER/(RMAX), (rand()-0.5*RMAX)*WINDOW_Y*POSITION_Y_MULTIPLIER/(RMAX), 0.0, 0.0));
//
//            //particles.push_back(new Particle(external_state, 1.0 / n, POSITION_X_MULTIPLIER*i, POSITION_Y_MULTIPLIER*j, 0.0, 0.0));
//            pixels.push_back(new DrawablePixel(*particles.back(), PARTICLE_SIZE_MULT, FRAME_LIM_MULTIPLIER));
//        }
//    }
//}
//
//void updateParticles(vector<Particle*>& particles){
//    for(auto particle: particles)
//        particle->calculateNextState();
//    for(auto particle: particles)
//    {
//        particle->update();
////       cout << particle->getX() << " " << particle->getY() << endl;
//    }
////    cout << "*********" << endl;
//}
//
//void updatePixels(vector<DrawablePixel*>& pixels){
//
//    for(auto pixel: pixels)
//    {
//        pixel->updateState();
//    }
//
//}
//
//void removeAndReplace(vector<Particle*>& particles, vector<DrawablePixel*>& pixels, double frame_lim_x, double frame_lim_y)
//{
//    auto num_removed = 0;
//    auto n = particles.size();
//
//    for(auto i=0; i<n; i++)
//    {
//        if(particles[i]->getX()>frame_lim_x  || particles[i]->getX()<-frame_lim_x  || particles[i]->getY()>frame_lim_y || particles[i]->getY()<-frame_lim_y)
//        {
//            delete particles[i];
//            delete pixels[i];
////            cout << "del" << endl;
////            if(num_removed%4==0) particles[i] = new Particle(external_state, 1.0/n, -frame_lim_x+num_removed, -frame_lim_y+num_removed, 0,0);
////            else if(num_removed%4==1) particles[i] = new Particle(external_state, 1.0/n, frame_lim_x-num_removed, -frame_lim_y+num_removed, 0,0);
////            else if(num_removed%4==2) particles[i] = new Particle(external_state, 1.0/n, -frame_lim_x+num_removed, frame_lim_y-num_removed, 0,0);
////            else particles[i] = new Particle(external_state, 1.0/n, frame_lim_x-num_removed, frame_lim_y-num_removed, 0,0);
//            if(num_removed%4==0) particles[i] = new Particle(external_state, PARTICLE_SIZE, 0, num_removed/10, 0,0);
//            else if(num_removed%4==1) particles[i] = new Particle(external_state, PARTICLE_SIZE, num_removed/10, num_removed/10, 0,0);
//            else if(num_removed%4==2) particles[i] = new Particle(external_state, PARTICLE_SIZE, 0, -num_removed/10, 0,0);
//            else particles[i] = new Particle(external_state, PARTICLE_SIZE, -num_removed/10, -num_removed/10, 0,0);
//
//            //particles[i] = new Particle(external_state, 1.0/n, frame_lim_x-num_removed/0.5, -frame_lim_y+num_removed/0.5, 0,0);
//            //particles[i] = new Particle(external_state, 1.0/n, external_state.attraction_point.x-num_removed, external_state.attraction_point.y-num_removed, 0,0);
//            pixels[i] = new DrawablePixel(*particles[i], PARTICLE_SIZE_MULT, FRAME_LIM_MULTIPLIER);
//            num_removed += 1;
//        }
//    }
//}

//void updateWindow(Window& window, vector<DrawablePixel*>& pixels)
//{
//    window.clear();
//    for(auto pixel: pixels)
//    {
//        window.draw(*pixel);
//    }
//
//    window.display();
//}
