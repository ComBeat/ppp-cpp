#include "../../std_lib_facilities.h"

namespace Point
{
class Point
{
    double x, y;

public:
    Point()
        : x(0), y(0){};
    Point(double, double);

    void   setX(double xToSet) { x = xToSet; }
    void   setY(double yToSet) { y = yToSet; }
    double getX() const { return x; }
    double getY() const { return y; }
};

ostream &operator<<(ostream &os, const Point &point);
}  // namespace Point
