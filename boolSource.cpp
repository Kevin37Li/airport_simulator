#include "boolSource.h"

/*****************************************************************************
 * boolSource constructor
 * ---------------------------------------------------------------------------
 * The unparametrized constructors for initialzing the member values within the
 * class
 * ---------------------------------------------------------------------------
 * setting up the private member value for class
 *****************************************************************************/
boolSource::boolSource(double p)
{
    assert(p >= 0 && p <= 1);

    probability = p;
}

/*****************************************************************************
 * query
 * --------------------------------------------------------------------------
 * This function returns true or false value based on the probability specified
 * by the user
 * ---------------------------------------------------------------------------
 * RETURN:
 *  true or false value based on the probability specified by the user
 *****************************************************************************/
bool boolSource::query() const
{
    return (rand() < probability * RAND_MAX);
}
