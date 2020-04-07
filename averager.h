#ifndef AIRPORT_SIMULATOR_AVERAGER_H
#define AIRPORT_SIMULATOR_AVERAGER_H


#include <cstdlib>
#include <cassert>

class averager {
public:
    // Constructor
    averager();

    // Modification Member Function
    void next_number(double value);

    // Constant Member Functions
    size_t how_many_numbers() const { return count; }
    double average() const;

private:
    // record how many numbers have been given to the averager
    size_t count;
    // sum of all the numbers given to teh averager
    double sum;
};

/*****************************************************************************
 * averager constructor
 * ---------------------------------------------------------------------------
 * The unparametrized constructors for initialzing the member values within the
 * class
 * ---------------------------------------------------------------------------
 * setting up the private member value for class
 *****************************************************************************/

/*****************************************************************************
 * next_number
 * --------------------------------------------------------------------------
 * This function takes in a number, and add it to the sum variable
 * ---------------------------------------------------------------------------
 * INPUT:
 *  value: the value entered by the user to calculate the average of the numbers
 *****************************************************************************/

/*****************************************************************************
 * how_many_numbers
 * --------------------------------------------------------------------------
 * This function returns how many numbers have entered by the user
 * ---------------------------------------------------------------------------
 * RETURN:
 *  the number of numbers have been entered by the user
 *****************************************************************************/

/*****************************************************************************
 * average
 * --------------------------------------------------------------------------
 * This function returns the average of the numbers entered by the user so far
 * ---------------------------------------------------------------------------
 * RETURN:
 *  the average of the numbers entered by the user so far
 *****************************************************************************/


#endif //AIRPORT_SIMULATOR_AVERAGER_H
