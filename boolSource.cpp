#include "boolSource.h"

boolSource::boolSource(double p)
{
    assert(p >= 0 && p <= 1);

    probability = p;
}

bool boolSource::query() const
{
    return (rand() < probability * RAND_MAX);
}
