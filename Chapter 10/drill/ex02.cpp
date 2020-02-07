// Chapter 10, exercise 02: create file of data like defined in §10.5; and fill
// it with at least 50 temperature readings; call the file it creates
// pics_and_txt/raw_temps.txt

#include "../std_lib_facilities.h"

const int maxTemp = 45;
const int minTemp = -50;

struct Reading
{
    int    hour;
    double temperature;

    Reading(int h, double t)
        : hour(h), temperature(t){};
};

ostream &operator<<(ostream &os, const Reading &r) {
    return os << r.hour << "\t\t" << r.temperature;
}

Reading create_Reading() {
    int    h             = randint(23);  // Min is 0
    double t             = randint(minTemp, maxTemp);
    double decimalNumber = randint(10);

    t += decimalNumber / 10;

    return Reading(h, t);
}

void write_readings(vector<Reading> &v, string fileName) {
    ofstream ost{fileName};

    if (!ost) error("Can't open file", fileName);

    for (Reading r : v)
        ost
        << r << endl;
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
