#include <iostream>
using namespace std;

// Function to input a vector
void inputVector(double* vector, int size, const string& name) {
    cout << "Enter elements of vector " << name << ":\n";
    for (int i = 0; i < size; ++i) {
        cin >> vector[i];
    }
}

// Function to calculate the magnitude of a vector
double magnitude(double* vector, int size) {
    double sum = 0;
    for (int i = 0; i < size; ++i) {
        sum += vector[i] * vector[i]; // Sum of squares
    }

    // Calculate the square root manually
    double mag = sum;
    double approx = 0.5 * mag;
    while (approx * approx - mag > 0.000001 || approx * approx - mag < -0.000001) {
        approx = 0.5 * (approx + mag / approx); // Newton-Raphson method
    }
    return approx;
}

// Function to calculate the dot product of two vectors
double dotProduct(double* vectorA, double* vectorB, int size) {
    double product = 0;
    for (int i = 0; i < size; ++i) {
        product += vectorA[i] * vectorB[i];
    }
    return product;
}

// Function to calculate the angle between two vectors in degrees
double angleBetweenVectors(double* vectorA, double* vectorB, int size) {
    double magA = magnitude(vectorA, size);
    double magB = magnitude(vectorB, size);
    double dot = dotProduct(vectorA, vectorB, size);

    // Calculate the cosine of the angle
    double cosTheta = dot / (magA * magB);

    // Clamp the cosine value to [-1, 1] to avoid floating-point precision issues
    if (cosTheta > 1.0) cosTheta = 1.0;
    if (cosTheta < -1.0) cosTheta = -1.0;

    // Calculate the angle in degrees manually
    double theta = cosTheta;
    double angle = theta;
    double term = theta; // Start of Taylor series expansion for acos
    for (int n = 1; n < 10; ++n) {
        term *= (theta * theta) * (2 * n - 1) / (2 * n); // Taylor series term
        angle += (n % 2 == 0 ? term : -term) / (2 * n + 1);
    }
    return angle * 180.0 / 3.14159; // Convert radians to degrees
}

// Main function
int main() {
    int size;
    cout << "Enter the size of the vectors: ";
    cin >> size;

    // Dynamically allocate arrays for the vectors
    double* vectorA = new double[size];
    double* vectorB = new double[size];

    inputVector(vectorA, size, "A");
    inputVector(vectorB, size, "B");

    double magA = magnitude(vectorA, size);
    double magB = magnitude(vectorB, size);
    double dot = dotProduct(vectorA, vectorB, size);
    double angle = angleBetweenVectors(vectorA, vectorB, size);

    cout << "Magnitude of vector A: " << magA << endl;
    cout << "Magnitude of vector B: " << magB << endl;
    cout << "Dot product of A and B: " << dot << endl;
    cout << "Angle between A and B (degrees): " << angle << endl;

    // Free dynamically allocated memory
    delete[] vectorA;
    delete[] vectorB;

    return 0;
}
