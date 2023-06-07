cmake_minimum_required(VERSION 3.14)
project(DifferentialEqns)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Window.cpp Window.h Drawable.h DrawablePixel.cpp DrawablePixel.h Particle.cpp Particle.h ExternalState.h InternalState.h EventType.h EventHandler.cpp EventHandler.h EventClose.h EventP.h EventSpace.h Simulation.cpp Simulation.h ExternalState.cpp)
add_executable(DifferentialEqns ${SOURCE_FILES})
include_directories(/usr/local/include)

find_package(SFML 2.5 COMPONENTS system window graphics network audio REQUIRED)
include_directories(${SFML_INCLUDE_DIRS})
target_link_libraries(DifferentialEqns sfml-system sfml-window sfml-graphics sfml-audio sfml-network)