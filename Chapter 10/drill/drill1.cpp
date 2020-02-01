#include "../../std_lib_facilities.h"
#include "Point.h"

int main() {
    vector<Point::Point> original_points(7);
    double               x, y;

    cout << "Please enter 7 pairs of (x, y): " << endl;
    for (int i = 0; i < original_points.size(); i++) {
        cout << i + 1 << ": ";
        cin >> x >> y;
        original_points[i].setX(x);
        original_points[i].setY(y);
    }

    for (Point::Point point : original_points)
        cout << point;
}
