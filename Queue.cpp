#include "Queue.h"
#include <cassert>

template <class T>
Queue<T>::Queue()
:_first(0), _last(CAPACITY-1), _size(0)
{}

template<class T>
void Queue<T>::pop() {
    assert(!empty());
    _first = next_index(_first);
    _size--;
}

template<class T>
void Queue<T>::push(const T &entry) {
    assert(size() < CAPACITY);

    _last = next_index(_last);
    data[_last] = entry;
    _size++;
}

template<class T>
T Queue<T>::front() const {
    assert(!empty());

    return data[_first];
}

