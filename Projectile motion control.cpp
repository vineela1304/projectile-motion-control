#include <iostream>
#include <cmath>
#include<iomanip>
using namespace std;

class VectorCalculator {
private:
    double vx, vy;

public:
    VectorCalculator() : vx(0.0), vy(0.0) {}

    void inputVxVy() {
        cout << "\nPlease enter the vx, vy values\n";
        cin >> vx >> vy;
    }

    void inputUThetaT() {
        double u, theta, t;
        const float g = 9.8;

        cout << "\nGive the input of u,theta,t\n";
        cin >> u >> theta >> t;

        double ntheta = degree(theta);
        double sinTheta = sinf(ntheta);
        double cosTheta = cosf(ntheta);

        vx = u * cosTheta;
        vy = u * sinTheta - (g * t);
    }

    void inputUThetaX() {
        double u, theta, x;
        const float g = 9.8;

        cout << "\nGive the input of u,theta,x\n";
        cin >> u >> theta >> x;

        double ntheta = degree(theta);
        double sinTheta = sinf(ntheta);
        double cosTheta = cosf(ntheta);

        double t = x / cosTheta;
        vx = u * cosTheta;
        vy = u * sinTheta - (g * t);
    }

    void displayResult() {
        int key;
        cout << "\nWhat do you want to display? 1) Magnitude 2) Angle 3) Vector\n";
        cin >> key;

        switch (key) {
            case 1: {
                double magnitude = sqrt(vx * vx + vy * vy);
                cout << "\nThe magnitude is " << fixed<<setprecision(2)<<magnitude << endl;
                break;
            }
            case 2: {
                double tanTheta = vy / vx;
                cout << "\nTan theta = " <<fixed<<setprecision(2)<< tanTheta << endl;
                break;
            }
            case 3: {
                cout << "\nThe vector form is " << fixed<<setprecision(2)<<vx << "i + " << fixed<<setprecision(2)<<vy << "j" << endl;
                break;
            }
            default: {
                cout << "\nWrong input\n";
            }
        }
    }

private:
    double degree(double x) {
        return x * 0.0174603175;
    }
};

int main() {
    int q;
    cout << "\nPress any key to continue and press '0' to exit\n";
    cin >> q;

    while (q != 0) {
        VectorCalculator vectorCalculator;
        int input;
        cout << "\nPlease choose the type of input:\n1) vx, vy\n2) u, theta, t\n3) u, theta, x\n";
        cin >> input;

        switch (input) {
            case 1:
                vectorCalculator.inputVxVy();
                break;
            case 2:
                vectorCalculator.inputUThetaT();
                break;
            case 3:
                vectorCalculator.inputUThetaX();
                break;
            default:
                cout << "Please choose the right key";
                break;
        }

        vectorCalculator.displayResult();

        cout << "\nPress any key to continue and press '0' to exit\n";
        cin >> q;
    }

    return 0;
}