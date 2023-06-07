# Simulate particle flow using differential equations

Still under devlopment

To run for the first time:
```
cmake .
```
To compile and run
```
make
./DifferentialEquations
```

To change differential equation for model:
Currently requires updating code and recompiling
* locate file *Particle.cpp*
* locate the body of the method, *void Particle::calculateNextState()*
* update  *next_state.x_1* and *next_state.y_1*
* For example, concentric circle flow can be modeled as:
    * next_state.x_1 = -y/(x*x+y*y);
    * next_state.y_1 = x/(x*x+y*y);

