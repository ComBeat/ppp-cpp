#include "../std_lib_facilities.h"

struct Reading
{
    int    hour;
    double temperature;

    Reading(int h, double t)
        : hour(h), temperature(t){};
};

istream &operator>>(istream &is, Reading &r) {
    int    hour        = 0;
    double temperature = 0.0;

    is >> hour >> temperature;
    if (!is) return is;
    r = Reading(hour, temperature);

    return is;
}

void meanTemperature(const vector<Reading> &v) {
    double sum = 0.0;

    for (Reading r : v)
        sum += r.temperature;

    cout << "The mean is: \t" << sum / v.size() << endl;
}

void medianTemperature(const vector<Reading> &v) {
    vector<double> temp;
    int            index = v.size() / 2;

    for (Reading r : v)
        temp.push_back(r.temperature);
    sort(temp);

    cout << "The median is: \t" << temp[index] << endl;
}

int main() {
    vector<Reading> readings;
    string          fileName = "raw_temps.txt";
    ifstream        ifs{fileName};

    if (!ifs) error("Couldn't open file", fileName);

    while (!ifs.eof()) {
        Reading r{0, 0.0};

        ifs >> r;
        readings.push_back(r);
    }
    readings.pop_back();

    meanTemperature(readings);
    medianTemperature(readings);
}
