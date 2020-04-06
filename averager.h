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


#endif //AIRPORT_SIMULATOR_AVERAGER_H
