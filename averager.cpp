#include "averager.h"


averager::averager()
:count(0), sum(0)
{}

void averager::next_number(double value)
{
    count++;
    sum += value;
}

double averager::average() const
{
    assert(how_many_numbers() > 0);
    return sum/how_many_numbers();
}
