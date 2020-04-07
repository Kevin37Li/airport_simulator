#ifndef AIRPORT_SIMULATOR_RUNWAY_H
#define AIRPORT_SIMULATOR_RUNWAY_H

#include <cassert>

class runway
{
public:
    // Constructor
    runway(unsigned int totalUsingTime = 20);

    // Modification Member Function
    void one_minute();
    void start_using();

    // Constant Member Function
    bool is_busy() const;

private:
    unsigned int _totalUsingTime;
    unsigned int _timeLeft;
};

/*****************************************************************************
 * runway constructor
 * ---------------------------------------------------------------------------
 * The unparametrized constructors for initialzing the member values within the
 * class
 * ---------------------------------------------------------------------------
 * setting up the private member value for class
 *****************************************************************************/

/*****************************************************************************
 * one_minute
 * --------------------------------------------------------------------------
 * This function records one minute for the in-use runway
 * ---------------------------------------------------------------------------
 * VOID FUNCTION
 *****************************************************************************/

/*****************************************************************************
 * start_using
 * --------------------------------------------------------------------------
 * This function indicates the user will start using the runway for
 * either takeoff or landing
 * ---------------------------------------------------------------------------
 * VOID FUNCTION
 *****************************************************************************/

/*****************************************************************************
 * is_busy
 * --------------------------------------------------------------------------
 * This function checks if the runway is currently under use of planes
 * ---------------------------------------------------------------------------
 * RETURN:
 *  true if the runway is being used right now, false otherwise
 *****************************************************************************/


#endif //AIRPORT_SIMULATOR_RUNWAY_H
