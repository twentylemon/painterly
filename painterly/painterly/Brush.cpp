

#include "Brush.h"


Brush::Brush() : _radius(0)
{
}

Brush::Brush(int radius) : _radius(radius)
{
}

int Brush::radius() const {
    return _radius;
}

void Brush::set_radius(int radius) {
    _radius = radius;
}

void Brush::reset() {
}

bool Brush::operator<(const Brush& rhs) const {
    return radius() < rhs.radius();
}
