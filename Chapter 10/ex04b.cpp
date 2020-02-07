//Gives wrong values. Probablly because of the input operator.

#include "../std_lib_facilities.h"

const char celsius    = 'c';
const char fahrenheit = 'f';

struct Reading
{
    int    hour;
    double temperature;
    char   suffix;

    Reading(int h, double t, char s)
        : hour(h), temperature(t), suffix(s){};
};

double celsiusToFahrenheit(double celsius);

istream &operator>>(istream &is, Reading &r) {
    int    hour        = 0;
    double temperature = 0.0;
    char   suffix;

    is >> hour >> temperature >> suffix;
    if (!is) return is;
    if (suffix == celsius)
        celsiusToFahrenheit(temperature);
    r = Reading(hour, temperature, fahrenheit);

    return is;
}

void meanTemperature(const vector<Reading> &v) {
    double sum = 0.0;

    for (Reading r : v)
        sum += r.temperature;

    cout << "The mean in Fahrenheit is: \t" << sum / v.size() << endl;
}

void medianTemperature(const vector<Reading> &v) {
    vector<double> temp;
    int            index = v.size() / 2;

    for (Reading r : v)
        temp.push_back(r.temperature);
    sort(temp);

    cout << "The median in Fahrenheit is: \t" << temp[index] << endl;
}

double celsiusToFahrenheit(double celsius) {
    return celsius *= 1.8 + 32;
}

int main() {
    vector<Reading> readings;
    string          fileName = "raw_temps.txt";
    ifstream        ifs{fileName};

    if (!ifs) error("Couldn't open file", fileName);

    while (!ifs.eof()) {
        Reading r{0, 0.0, '0'};

        ifs >> r;
        readings.push_back(r);
    }
    readings.pop_back();

    meanTemperature(readings);
    medianTemperature(readings);
}
