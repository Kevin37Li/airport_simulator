#include "averager.h"

/*****************************************************************************
 * averager constructor
 * ---------------------------------------------------------------------------
 * The unparametrized constructors for initialzing the member values within the
 * class
 * ---------------------------------------------------------------------------
 * setting up the private member value for class
 *****************************************************************************/
averager::averager()
:count(0), sum(0)
{}

/*****************************************************************************
 * next_number
 * --------------------------------------------------------------------------
 * This function takes in a number, and add it to the sum variable
 * ---------------------------------------------------------------------------
 * INPUT:
 *  value: the value entered by the user to calculate the average of the numbers
 *****************************************************************************/
void averager::next_number(double value)
{
    count++;
    sum += value;
}

/*****************************************************************************
 * average
 * --------------------------------------------------------------------------
 * This function returns the average of the numbers entered by the user so far
 * ---------------------------------------------------------------------------
 * RETURN:
 *  the average of the numbers entered by the user so far
 *****************************************************************************/
double averager::average() const
{
    assert(how_many_numbers() > 0);
    return sum/how_many_numbers();
}
