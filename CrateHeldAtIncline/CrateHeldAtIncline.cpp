#include <iostream>
#include <cmath>
#include <string>

using namespace std;

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif


// Function to calculate the force parallel to the incline
double calculateForce(double weight, double angle, bool fromHorizontal) {
    // If the angle is from the horizontal, use sin for parallel force
    // If the angle is from the vertical, use cos for parallel force
    return weight * (fromHorizontal ? sin(angle * M_PI / 180.0) : cos(angle * M_PI / 180.0));
}

// Function to explain the calculation
void explainCalculation(bool fromHorizontal) {
    if (fromHorizontal) {
        cout << "Since the angle is from the horizontal, we use the sine function to calculate the force parallel to the incline." << endl;
        cout << "The force perpendicular to the incline is calculated using the cosine function." << endl;
    }
    else {
        cout << "Since the angle is from the vertical, we use the cosine function to calculate the force parallel to the incline." << endl;
        cout << "The force perpendicular to the incline is calculated using the sine function." << endl;
    }
}

int main() {
    double weight, angle;
    char understand, angleFrom;
    bool fromHorizontal, running = true;

    while (running) {
        cout << "Enter the weight of the crate (in newtons): ";
        cin >> weight;

        cout << "Is the angle measured from the horizontal or the vertical? (H/V): ";
        cin >> angleFrom;
        fromHorizontal = (angleFrom == 'H' || angleFrom == 'h');

        cout << "Enter the angle of the incline (in degrees): ";
        cin >> angle;

        double parallelForce = calculateForce(weight, angle, fromHorizontal);
        double perpendicularForce = calculateForce(weight, angle, !fromHorizontal);

        cout << "Calculating the force parallel to the incline..." << endl;
        cout << "Parallel Force = " << weight << " * " << (fromHorizontal ? "sin" : "cos") << "(" << angle << ") = " << parallelForce << " N" << endl;
        cout << "Do you understand this step? (Y/N): ";
        cin >> understand;
        if (understand == 'N' || understand == 'n') {
            explainCalculation(fromHorizontal);
        }

        cout << "Calculating the force perpendicular to the incline..." << endl;
        cout << "Perpendicular Force = " << weight << " * " << (fromHorizontal ? "cos" : "sin") << "(" << angle << ") = " << perpendicularForce << " N" << endl;
        cout << "Do you understand this step? (Y/N): ";
        cin >> understand;
        if (understand == 'N' || understand == 'n') {
            explainCalculation(!fromHorizontal);
        }

        cout << "Would you like to calculate another problem? (Y/N): ";
        cin >> understand;
        if (understand == 'N' || understand == 'n') {
            running = false;
        }
    }

    return 0;
}