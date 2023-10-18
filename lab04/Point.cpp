//
// Created by balaz on 2023. 10. 18..
//

#include <valarray>
#include "Point.h"

Point::Point(int x, int y) {
    if(x < 0 || x > M) {
        x = 0;
    }
    if(y < 0 || y > M) {
        y = 0;
    }
    this->x = x;
    this->y = y;
}

int Point::getX() const {
    return x;
}

int Point::getY() const {
    return y;
}

double Point::distanceTo(const Point& point) const {
    int dx = this->x - point.x;
    int dy = this->y - point.y;
    return sqrt(dx*dx + dy*dy);
}
