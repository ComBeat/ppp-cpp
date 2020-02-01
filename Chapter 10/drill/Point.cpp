#include "Point.h"

namespace Point
{
Point::Point(double xToSet, double yToSet) {
    x = xToSet;
    y = yToSet;
}

ostream &operator<<(ostream &os, const Point &point) {
    return os << '(' << point.getX() << ", " << point.getY() << ')' << endl;
}
}  // namespace Point
