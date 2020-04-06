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


#endif //AIRPORT_SIMULATOR_RUNWAY_H
