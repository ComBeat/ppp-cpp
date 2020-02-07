#include "../std_lib_facilities.h"

const int maxTemp = 45;
const int minTemp = -50;

struct Reading
{
    int    hour;
    double temperature;
    char   suffix;

    Reading(int h, double t, char s)
        : hour(h), temperature(t), suffix(s){};
};

ostream &operator<<(ostream &os, const Reading &r) {
    return os << r.hour << "\t\t" << r.temperature << r.suffix;
}

Reading create_Reading() {
    int    h             = randint(23);  // Min is 0
    double t             = randint(minTemp, maxTemp);
    double decimalNumber = randint(10);
    int    rand          = randint(1);
    char   s             = 0;

    t += decimalNumber / 10;
    if (rand)
        s = 'c';
    else
        s = 'f';

    return Reading(h, t, s);
}

void write_readings(vector<Reading> &v, string fileName) {
    ofstream ost{fileName};

    if (!ost) error("Can't open file", fileName);

    for (Reading r : v)
        ost << r << endl;
}

int main() {
    string          fileName = "raw_temps.txt";
    vector<Reading> readings;

    try {
        for (int i = 0; i < 50; i++)
            readings.push_back(create_Reading());
        write_readings(readings, fileName);
    } catch (exception &e) {
        cerr << e.what() << endl;
    }
}
