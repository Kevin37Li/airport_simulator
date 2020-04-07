#include "Queue.h"
#include <cassert>

/*****************************************************************************
 * Queue constructor
 * ---------------------------------------------------------------------------
 * The unparametrized constructors for initialzing the member values within the
 * class
 * ---------------------------------------------------------------------------
 * setting up the private member value for class
 *****************************************************************************/
template <class T>
Queue<T>::Queue()
:_first(0), _last(CAPACITY-1), _size(0)
{}

/*****************************************************************************
 * pop
 * ---------------------------------------------------------------------------
 * Removes the front of this queue.
 * ---------------------------------------------------------------------------
 * void function
 *****************************************************************************/
template<class T>
void Queue<T>::pop() {
    assert(!empty());
    _first = next_index(_first);
    _size--;
}

/*****************************************************************************
 * push
 * --------------------------------------------------------------------------
 * This function inserts a data value at the rear of the queue.
 * ---------------------------------------------------------------------------
 * INPUTS:
 *  entry: the new value to be inserted
 *****************************************************************************/
template<class T>
void Queue<T>::push(const T &entry) {
    assert(size() < CAPACITY);

    _last = next_index(_last);
    data[_last] = entry;
    _size++;
}

/*****************************************************************************
 * front
 * ---------------------------------------------------------------------------
 * rReturns the front of the queue.
 * ---------------------------------------------------------------------------
 * RETURN:
 *  the front element of the queue
 *****************************************************************************/
template<class T>
T Queue<T>::front() const {
    assert(!empty());

    return data[_first];
}

