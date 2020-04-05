#include <iostream>
using namespace std;

int main() {

    cout << "The amount of time needed for one plane to land: ";
    double landingTime;
    cin >> landingTime;

    cout << "The amount of time need for one plane to take off: ";
    double takeoffTime;
    cin >> takeoffTime;

    cout << "The average amount of time between arrival of planes to the landing queue: ";
    double a;
    cin >> a;

    cout << "The average amount of time between arrival of planes to the takeoff queue: ";
    double b;
    cin >> b;

    cout << "The maximum amount of time that a plane can stay in the landing queue without "
            "running out of fuel and crashing: ";
    double maxWaitingTime;
    cin >> maxWaitingTime;

    cout << "The total length of time to be simulated: ";
    double timeTotal;
    cin >> timeTotal;







    return 0;
}
