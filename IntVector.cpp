// IntVector.cpp

#include "IntVector.h"
#include <iostream>

using namespace std;

// Constructor
IntVector::IntVector(unsigned capacity, int value){
    _size = capacity;
    _capacity = capacity;
    if (capacity > 0) {
        _data = new int[capacity];
        for (unsigned i = 0; i < capacity; ++i) {
            _data[i] = value;
        }
    } else {
        _data = nullptr;
    }
}

// Destructor
IntVector::~IntVector() {
    delete[] _data;
}

// Accessors
unsigned IntVector::size() const {
    return _size;
}

unsigned IntVector::capacity() const {
    return _capacity;
}

bool IntVector::empty() const {
    return _size == 0;
}

const int & IntVector::at(unsigned index) const {
    if (index >= _size) {
        throw out_of_range("IntVector::at_range_check");
    }
    return _data[index];
}

const int & IntVector::front() const {
    return _data[0];
}

const int & IntVector::back() const {
    return _data[_size - 1];
}

void IntVector::expand() {
    int* temp = _data;

    if (_capacity == 0) {
        _capacity = 1;
        _data = new int[_capacity];
        return;
    }
    else{
        _capacity *= 2;
        _data = new int[_capacity];
        for (unsigned i = 0; i < _size; ++i) {
            _data[i] = temp[i];
        }
    }
    delete[] temp;
}

void IntVector::expand(unsigned int amount) {
    int* temp = _data;

    if (_capacity == 0) {
        _capacity = amount;
        _data = new int[_capacity];
        return;
    }
    else {
        _capacity += amount;
        _data = new int[_capacity];
        for (unsigned i = 0; i < _size; ++i) {
            _data[i] = temp[i];
        }
    }
    delete[] temp;
}

void IntVector::insert(unsigned index, int value) {
    if (index > _size) {
        throw std::out_of_range("IntVector::insert_range_check");
    }
    if (_size == _capacity) {
        expand();
    }
    for (unsigned i = index; i < _size; ++i) {
        _data[i+1] = _data[i];
    }
    _data[index] = value;
    ++_size;
}

void IntVector::erase(unsigned index) {
    if (index >= _size) {
        throw std::out_of_range("IntVector::erase_range_check");
    }
    for (unsigned i = index; i < _size-1; ++i) {
        _data[i] = _data[i + 1];
    }
    --_size;
}

void IntVector::push_back(int value) {
    if (_size == _capacity) {
        expand();
    }
    _data[_size] = value;
    ++_size;
}

void IntVector::pop_back() {
    --_size;
}

void IntVector::clear() {
    _size = 0;
}

void IntVector::resize(unsigned int size, int value) {
    if (size > _capacity) {
        if(size > _capacity*2){
            expand(size - _capacity);
        }
        else{
            expand();
        }
    }
    if (size > _size) {
        for (unsigned i = _size; i < size; ++i) {
            _data[i] = value;
        }
    }
    _size = size;
}

void IntVector::reserve(unsigned int n) {
    if (n > _capacity) {
        expand(n - _capacity);
    }
}

void IntVector::assign(unsigned int n, int value) {
    if (n > _capacity) {
        if(n > _capacity*2){
            expand(n - _capacity);
        }
        else{
            expand(_capacity);
        }
    }
    for (unsigned i = 0; i < n; ++i) {
        _data[i] = value;
    }
    _size = n;
}

int & IntVector::at(unsigned index) {
    if (_size == 0  || index >= _size) {
        throw std::out_of_range("IntVector::at_range_check");
    }
    return _data[index];
}

int & IntVector::front() {
    return _data[0];
}

int & IntVector::back() {
    return _data[_size - 1];
}
