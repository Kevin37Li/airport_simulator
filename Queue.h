#ifndef AIRPORT_SIMULATOR_QUEUE_H
#define AIRPORT_SIMULATOR_QUEUE_H

#include <iostream>

using namespace std;

template <class T>
class Queue{
public:
    typedef size_t size_type;
    static const size_type  CAPACITY = 100;

    // constructor
    Queue();

    // modification member functions
    void pop();
    void push(const T& entry);

    // constant member functions
    bool empty() const { return size() == 0; }
    T front() const;
    size_type size() const { return _size; }

private:
    size_type _first;           // index of the front of the Queue
    size_type _last;            // index of the rear of the Queue
    size_type _size;            // total number of items in the Queue

    T data[CAPACITY];  // circular array

    // helper member function
    size_type next_index(size_type i) const { return (i+1)%CAPACITY; }
};


#endif //AIRPORT_SIMULATOR_QUEUE_H


