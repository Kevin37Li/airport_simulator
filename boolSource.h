#ifndef AIRPORT_SIMULATOR_BOOLSOURCE_H
#define AIRPORT_SIMULATOR_BOOLSOURCE_H

#include <iostream>
#include <cstdlib>
#include <cassert>

using namespace std;

class boolSource {
public:
    // Constructor
    boolSource(double p = 0.5);

    // Constant Member Function
    bool query() const;

private:
    // probability fo query() retuning true
    double probability;

};
/*****************************************************************************
 * boolSource constructor
 * ---------------------------------------------------------------------------
 * The unparametrized constructors for initialzing the member values within the
 * class
 * ---------------------------------------------------------------------------
 * setting up the private member value for class
 *****************************************************************************/

/*****************************************************************************
 * query
 * --------------------------------------------------------------------------
 * This function returns true or false value based on the probability specified
 * by the user
 * ---------------------------------------------------------------------------
 * RETURN:
 *  true or false value based on the probability specified by the user
 *****************************************************************************/


#endif //AIRPORT_SIMULATOR_BOOLSOURCE_H
