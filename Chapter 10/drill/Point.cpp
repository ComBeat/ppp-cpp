#include "Point.h"

namespace Point
{
ostream &operator<<(ostream &os, const Point &point) {
    return os << '(' << point.get_x() << ", " << point.get_y() << ')' << endl;
}

istream &operator>>(istream &is, Point &point) {
    int  x, y;
    char ch0, ch1, ch2;

    is >> ch0 >> x >> ch1 >> y >> ch2;
    if (ch0 != '(' || ch1 != ',' || ch2 != ')') {
        is.clear(ios_base::failbit);
        return is;
    }

    point = Point(x, y);

    return is;
}

bool operator==(const Point &p0, const Point &p1) {
    return p0.get_x() == p1.get_x() && p0.get_y() == p1.get_y();
}

bool operator!=(const Point &p0, const Point &p1) {
    return !(p0 == p1);
}
}  // namespace Point
