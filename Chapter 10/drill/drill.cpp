#include "../../std_lib_facilities.h"
#include "Point.h"

int main() {
    vector<Point::Point> original_points(7);
    vector<Point::Point> processed_points;
    double               x, y;
    string               fname{"mydata.txt"};
    ofstream             ofs{fname};
    ifstream             ifs{fname};
    string               error_msg{"Something's wrong!"};

    if (!ofs) error("Can't open output file!", fname);

    cout << "Please enter 7 pairs of (x,y): " << endl;
    for (int i = 0; i < original_points.size(); i++) {
        cout << i + 1 << ": ";
        cin >> x >> y;
        original_points[i].set_x(x);
        original_points[i].set_y(y);
    }

    for (Point::Point point : original_points) {
        ofs << point;
    }
    ofs.close();

    if (!ifs) error("Can't open input file!", fname);
    while (!ifs.eof()) {
        Point::Point p;
        if (!(ifs >> p)) break;
        processed_points.push_back(p);
    }
    ifs.close();

    cout << "original_points:" << endl;
    for (Point::Point p : original_points)
        cout << p;
    cout << "processed_points: " << endl;
    for (Point::Point p : processed_points)
        cout << p;

    //Compare both vectors
    if (original_points.size() != processed_points.size())
        error(error_msg, "Differ in size");
    for (int i = 0; i < original_points.size(); i++) {
        if (original_points[i] != processed_points[i])
            error(error_msg, i);
    }

    cout << "It's all good!" << endl;
}
