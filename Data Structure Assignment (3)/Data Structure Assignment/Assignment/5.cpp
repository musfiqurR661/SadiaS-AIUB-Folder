#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

const double R = 6371.0; // Earth's radius in kilometers

class Country {
public:
    string code;
    double latitude;
    double longitude;
    string countryName;

    Country(string c, double lat, double lon, string name)
        : code(c), latitude(lat), longitude(lon), countryName(name) {}
};

// Convert degrees to radians
double toRadians(double degree) {
    return degree * (3.141592653589793 / 180.0);
}

// Compute power (x^y)
double power(double base, int exp) {
    double result = 1.0;
    for (int i = 0; i < exp; i++) {
        result *= base;
    }
    return result;
}

// Compute factorial
double factorial(int n) {
    double result = 1;
    for (int i = 2; i <= n; i++) {
        result *= i;
    }
    return result;
}

// Compute sine using Taylor series
double sine(double x) {
    double sinVal = 0.0;
    for (int i = 0; i < 10; i++) {
        int sign = (i % 2 == 0) ? 1 : -1; // Alternate signs
        sinVal += sign * power(x, 2 * i + 1) / factorial(2 * i + 1);
    }
    return sinVal;
}

// Compute cosine using Taylor series
double cosine(double x) {
    double cosVal = 0.0;
    for (int i = 0; i < 10; i++) {
        int sign = (i % 2 == 0) ? 1 : -1; // Alternate signs
        cosVal += sign * power(x, 2 * i) / factorial(2 * i);
    }
    return cosVal;
}

// Compute square root using Newton's method
double squareRoot(double num) {
    double x = num;
    double root;
    int i = 0;
    while (true) {
        root = 0.5 * (x + (num / x));
        if (abs(root - x) < 0.00001) // Stop when precision is high
            break;
        x = root;
        i++;
    }
    return root;
}

// Compute haversine distance
double haversineDistance(double lat1, double lon1, double lat2, double lon2) {
    lat1 = toRadians(lat1);
    lon1 = toRadians(lon1);
    lat2 = toRadians(lat2);
    lon2 = toRadians(lon2);

    double dLat = lat2 - lat1;
    double dLon = lon2 - lon1;

    double a = power(sine(dLat / 2), 2) + cosine(lat1) * cosine(lat2) * power(sine(dLon / 2), 2);
    double c = 2 * atan2(squareRoot(a), squareRoot(1 - a));

    return R * c; // Distance in kilometers
}

// Load country data from file
void loadCountries(const string &filename, vector<Country> &countries) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error: Unable to open file " << filename << endl;
        return;
    }

    string code, name;
    double lat, lon;
    while (file >> code >> lat >> lon) {
        file.ignore(); // Ignore the space before the country name
        getline(file, name);
        countries.emplace_back(code, lat, lon, name);
    }

    file.close();
}

// Find distance between two countries by their codes
void findDistanceBetweenCountries(const vector<Country> &countries, const string &code1, const string &code2) {
    const Country *country1 = nullptr;
    const Country *country2 = nullptr;

    for (const auto &country : countries) {
        if (country.code == code1) {
            country1 = &country;
        }
        if (country.code == code2) {
            country2 = &country;
        }
    }

    if (country1 && country2) {
        double distance = haversineDistance(country1->latitude, country1->longitude,
                                            country2->latitude, country2->longitude);
        cout << "The distance between " << country1->countryName << " and " << country2->countryName
             << " is " << distance << " kilometers." << endl;
    } else {
        cout << "One or both country codes not found." << endl;
    }
}

int main() {
    vector<Country> countries;
    string filename = "g:/SADIA/Data Structure Assignment (3)/Data Structure Assignment/country.txt";

    loadCountries(filename, countries);

    string code1, code2;
    cout << "Enter the code of the first country: ";
    cin >> code1;
    cout << "Enter the code of the second country: ";
    cin >> code2;

    findDistanceBetweenCountries(countries, code1, code2);

    return 0;
}
