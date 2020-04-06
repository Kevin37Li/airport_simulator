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


#endif //AIRPORT_SIMULATOR_BOOLSOURCE_H
