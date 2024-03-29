#ifndef FORMA2D_H
#define FORMA2D_H

#include "forma.h"

class Forma2D : public Forma
{
public:

    virtual double get_area() = 0;
    virtual double get_perimetro() = 0;

    virtual ~Forma2D() {}
};

#endif