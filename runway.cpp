#include "runway.h"

/*****************************************************************************
 * runway constructor
 * ---------------------------------------------------------------------------
 * The unparametrized constructors for initialzing the member values within the
 * class
 * ---------------------------------------------------------------------------
 * setting up the private member value for class
 *****************************************************************************/
runway::runway(unsigned int totalUsingTime)
:_totalUsingTime(totalUsingTime), _timeLeft(0)
{}

/*****************************************************************************
 * one_minute
 * --------------------------------------------------------------------------
 * This function records one minute for the in-use runway
 * ---------------------------------------------------------------------------
 * VOID FUNCTION
 *****************************************************************************/
void runway::one_minute()
{
    if(is_busy())
    {
        _timeLeft--;
    }
}

/*****************************************************************************
 * start_using
 * --------------------------------------------------------------------------
 * This function indicates the user will start using the runway for
 * either takeoff or landing
 * ---------------------------------------------------------------------------
 * VOID FUNCTION
 *****************************************************************************/
void runway::start_using()
{
    assert(!is_busy());
    _timeLeft = _totalUsingTime;
}

/*****************************************************************************
 * is_busy
 * --------------------------------------------------------------------------
 * This function checks if the runway is currently under use of planes
 * ---------------------------------------------------------------------------
 * RETURN:
 *  true if the runway is being used right now, false otherwise
 *****************************************************************************/
bool runway::is_busy() const {
    return _timeLeft > 0;
}
