#include <iostream>
#include "Queue.h"
#include "boolSource.h"
#include "averager.h"

using namespace std;

bool isPlaneCrashed(unsigned int timeEnteringQueue, unsigned int timeToLand,
        unsigned int maxWaitingTime);

int main() {

    cout << "The amount of time needed for one plane to land: ";
    double landingTime;
    cin >> landingTime;

    cout << "The amount of time need for one plane to take off: ";
    double takeoffTime;
    cin >> takeoffTime;

    cout << "The average amount of time between arrival of planes to the landing queue: ";
    double avgTimeEnteringLandingQueue;
    cin >> avgTimeEnteringLandingQueue;

    cout << "The average amount of time between arrival of planes to the takeoff queue: ";
    double avgTimeEnteringTakeoffQueue;
    cin >> avgTimeEnteringTakeoffQueue;

    cout << "The maximum amount of time that a plane can stay in the landing queue without "
            "running out of fuel and crashing: ";
    unsigned int maxWaitingTime;
    cin >> maxWaitingTime;

    cout << "The total length of time to be simulated: ";
    unsigned int timeTotal;
    cin >> timeTotal;

    Queue<unsigned int> landingQueue;
    Queue<unsigned int> takeoffQueue;

    boolSource isComingToLandingQueue(1/avgTimeEnteringLandingQueue);
    boolSource isComingToTakeoffQueue(1/avgTimeEnteringTakeoffQueue);

    averager landingPlanes;
    averager takeoffPlanes;

    size_t planesCrashed = 0;

    for(unsigned int i = 1; i <= timeTotal; i++)
    {
        if(isComingToLandingQueue.query())
        {
            landingQueue.push(i);
        }

        if(isComingToTakeoffQueue.query())
        {
            takeoffQueue.push(i);
        }

        while (!landingQueue.empty() && isPlaneCrashed(landingQueue.front(), i, maxWaitingTime))
        {
            landingQueue.pop();
            planesCrashed++;
        }

        if(!landingQueue.empty())
        {

        }
    }


    return 0;
}


bool isPlaneCrashed(unsigned int timeEnteringQueue, unsigned int timeToLand,
                    unsigned int maxWaitingTime)
{
    return timeToLand - timeEnteringQueue > maxWaitingTime;
}


