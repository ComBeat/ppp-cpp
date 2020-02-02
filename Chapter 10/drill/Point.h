#include "../../std_lib_facilities.h"

namespace Point
{
class Point
{
    int x, y;

public:
    Point()
        : x(0), y(0){};
    Point(int xToSet, int yToSet)
        : x(xToSet), y(yToSet){};

    void set_x(int xToSet) { x = xToSet; }
    void set_y(int yToSet) { y = yToSet; }
    int  get_x() const { return x; }
    int  get_y() const { return y; }
};

ostream &operator<<(ostream &os, const Point &point);
istream &operator>>(istream &is, Point &point);
bool     operator==(const Point &p0, const Point &p1);
bool     operator!=(const Point &p0, const Point &p1);
}  // namespace Point
