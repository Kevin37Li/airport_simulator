#include <iostream>
#include "Queue.h"
#include "Queue.cpp"
#include "boolSource.h"
#include "averager.h"
#include "runway.h"

using namespace std;

bool isPlaneCrashed(unsigned int timeEnteringQueue, unsigned int timeToLand,
        unsigned int maxWaitingTime);

int main() {

    cout << "-----------------------------------INPUT-----------------------------------------" << endl;
    cout << "The amount of time needed for one plane to land: ";
    unsigned int landingTime;
    cin >> landingTime;

    cout << "The amount of time need for one plane to take off: ";
    unsigned int takeoffTime;
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

    runway runwayForLanding(landingTime);
    runway runwayForTakeoff(takeoffTime);

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

        if(!runwayForLanding.is_busy() && !runwayForTakeoff.is_busy() && !landingQueue.empty())
        {
            unsigned int next = landingQueue.front();
            landingQueue.pop();
            landingPlanes.next_number(i-next);

            runwayForLanding.start_using();
        }

        if(!landingQueue.empty())
        {
            runwayForLanding.one_minute();
            runwayForTakeoff.one_minute();
            continue;
        }

        if (!runwayForLanding.is_busy() && !runwayForTakeoff.is_busy() && !takeoffQueue.empty())
        {
            unsigned int next = takeoffQueue.front();
            takeoffQueue.pop();
            takeoffPlanes.next_number(i-next);

            runwayForTakeoff.start_using();
        }

        runwayForLanding.one_minute();
        runwayForTakeoff.one_minute();
    }

    cout << endl;
    cout << "-----------------------------------OUTPUT-----------------------------------------" << endl;
    cout << "The number of planes that took off in the simulated time: "
    << takeoffPlanes.how_many_numbers() << endl;
    cout << "The number of planes that landed in the simulated time: "
    << landingPlanes.how_many_numbers() << endl;
    cout << "The number of planes that crashed because the ran out of fuel before they"
            "could land: " << planesCrashed << endl;
    cout << "The average time that a plane spent in the takeoff queue: "
    << takeoffPlanes.average() << endl;
    cout << "The average time that a plane spent in the landing queue: "
    << landingPlanes.average() << endl;

    return 0;
}


bool isPlaneCrashed(unsigned int timeEnteringQueue, unsigned int timeToLand,
                    unsigned int maxWaitingTime)
{
    return timeToLand - timeEnteringQueue > maxWaitingTime;
}


