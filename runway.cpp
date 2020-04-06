#include "runway.h"

runway::runway(unsigned int totalUsingTime)
:_totalUsingTime(totalUsingTime), _timeLeft(0)
{}

void runway::one_minute()
{
    if(is_busy())
    {
        _timeLeft--;
    }
}

void runway::start_using()
{
    assert(!is_busy());
    _timeLeft = _totalUsingTime;
}

bool runway::is_busy() const {
    return _timeLeft > 0;
}
