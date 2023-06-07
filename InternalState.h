//
// Created by Aaron Fainman on 2021/12/08.
//

#ifndef DIFFERENTIALEQNS_INTERNALSTATE_H
#define DIFFERENTIALEQNS_INTERNALSTATE_H

struct InternalState{
    InternalState(double size_, double start_x, double start_y, double start_x_1, double start_y_1)
            : size{size_}, x{start_x}, y{start_y}, x_1{start_x_1}, y_1{start_y_1}
    {   }

    InternalState(InternalState& obj)
        : x{obj.x},x_1{obj.x_1}, y{obj.y}, y_1{obj.y_1}, size{obj.size}
    {   }
    double x;
    double x_1;
    double y;
    double y_1;
    double size;
};

#endif //DIFFERENTIALEQNS_INTERNALSTATE_H
