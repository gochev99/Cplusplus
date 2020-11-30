#pragma once
#include <stdexcept>

template <typename T>
class Stack
{
private:
    T* data;
    size_t size;
    size_t capacity;

    void copy(const Stack& other);
    void erase();
    void resize();
public:
    Stack(size_t initialCapacity = 8);
    Stack(const Stack& other);
    Stack& operator=(const Stack& other);
    ~Stack();

    bool isEmpty() const;
    void push(const T& element);
    T& pop();
    size_t getSize() const;
};

#include "StackDA.inl"
