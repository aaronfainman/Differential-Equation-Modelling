//
// Created by Aaron Fainman on 2021/12/08.
//

#ifndef DIFFERENTIALEQNS_DRAWABLE_H
#define DIFFERENTIALEQNS_DRAWABLE_H

#include "Window.h"

class Drawable {
public:
    virtual void draw(Window& window) = 0;

};


#endif //DIFFERENTIALEQNS_DRAWABLE_H
