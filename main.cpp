/*****************************************************************************
 * Author     : Weiyuan Li
 * Assignment : Airport Simulation
 * Class      : CS 08
 * Section    : M-TR:9:45 - 11:05
 * DUE DATE   : 04/05/20
 ****************************************************************************/

#include <iostream>
#include "Queue.h"
#include "Queue.cpp"
#include "boolSource.h"
#include "averager.h"
#include "runway.h"

using namespace std;

/*****************************************************************************
 * isPlaneCrashed
 * --------------------------------------------------------------------------
 * check to see if the plane has crashed
 * ---------------------------------------------------------------------------
 * INPUTS:
 *  timeEnteringQueue: the time the plane entered the landing queue
 *  timeToLand: the time the plane began to land
 *  maxWaitingTime: the max time a plane can wait in the landing queue before crashing
 *****************************************************************************/
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

    // using the for loop to simulate the time
    for(unsigned int i = 1; i <= timeTotal; i++)
    {
        // check if there are planes coming to the landing queue
        if(isComingToLandingQueue.query())
        {
            landingQueue.push(i);
        }

        // check if there are planes coming into the takeoff queue
        if(isComingToTakeoffQueue.query())
        {
            takeoffQueue.push(i);
        }

        // if the landing queue is not empty and there are planes crashing
        while (!landingQueue.empty() && isPlaneCrashed(landingQueue.front(), i, maxWaitingTime))
        {
            // remove the crashed planes
            landingQueue.pop();
            planesCrashed++;
        }

        // if there are not plane currently occupying the runway
        // and the landing queue is not empty, ready to land a plane
        if(!runwayForLanding.is_busy() && !runwayForTakeoff.is_busy() && !landingQueue.empty())
        {
            unsigned int next = landingQueue.front();
            landingQueue.pop();
            landingPlanes.next_number(i-next);

            // start using the runway for landing
            runwayForLanding.start_using();
        }

        // check if the landing queue is empty or not
        if(!landingQueue.empty())
        {
            // recorded one minute for runway either in use of takeoff or landing
            runwayForLanding.one_minute();
            runwayForTakeoff.one_minute();
            continue;
        }

        // check if the runway is currently occupied and if the take off queue is empty
        if (!runwayForLanding.is_busy() && !runwayForTakeoff.is_busy() && !takeoffQueue.empty())
        {
            unsigned int next = takeoffQueue.front();
            takeoffQueue.pop();
            takeoffPlanes.next_number(i-next);

            // start using the runway for takeoff
            runwayForTakeoff.start_using();
        }

        // recorded one minute for runway either in use of takeoff or landing
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

/*****************************************************************************
 * isPlaneCrashed
 * --------------------------------------------------------------------------
 * check to see if the plane has crashed
 * ---------------------------------------------------------------------------
 * INPUTS:
 *  timeEnteringQueue: the time the plane entered the landing queue
 *  timeToLand: the time the plane began to land
 *  maxWaitingTime: the max time a plane can wait in the landing queue before crashing
 *****************************************************************************/
bool isPlaneCrashed(unsigned int timeEnteringQueue, unsigned int timeToLand,
                    unsigned int maxWaitingTime)
{
    return timeToLand - timeEnteringQueue > maxWaitingTime;
}


