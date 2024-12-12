#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
using namespace std;

// Structure to store point data
struct Point {
    string name;
    int x;
    int y;
};

// Function to calculate the distance from the origin
double calculateDistance(int x, int y) {
    return sqrt(x * x + y * y); // Euclidean distance formula
}

// Function to find the point farthest from the origin
Point findFarthestPoint(Point points[], int size) {
    Point farthest = points[0];
    double maxDistance = calculateDistance(points[0].x, points[0].y);

    for (int i = 1; i < size; ++i) {
        double distance = calculateDistance(points[i].x, points[i].y);
        if (distance > maxDistance) {
            maxDistance = distance;
            farthest = points[i];
        }
    }
    return farthest;
}

int main() {
    // Reading data from file
    ifstream file("g:/SADIA/Data Structure Assignment (3)/Data Structure Assignment/point.txt");
    if (!file.is_open()) {
        cerr << "Unable to open file." << endl;
        return 1;
    }

    const int MAX_POINTS = 100;
    Point points[MAX_POINTS];
    int index = 0;

    while (file && index < MAX_POINTS) {
        file >> points[index].name >> points[index].x >> points[index].y;
        ++index;
    }

    file.close();

    // Finding the farthest point
    Point farthest = findFarthestPoint(points, index);
    double distance = calculateDistance(farthest.x, farthest.y);

    // Output the result
    cout << "The farthest point from the origin is: " << farthest.name << " (" << farthest.x << ", " << farthest.y << ")" << endl;
    cout << "Distance from the origin: " << distance << endl;

    return 0;
}
