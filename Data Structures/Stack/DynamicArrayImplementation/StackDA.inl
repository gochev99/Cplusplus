#pragma once

template <typename T>
void Stack<T>::copy(const Stack<T>& other) // data(nullptr) (?)
{
    this->data = new T[other.capacity];
    this->capacity = other.capacity;
    this->size = other.size;
    for(size_t i = 0; i < this->size; ++i)
    {
        this->data[i] = other.data[i];
    }
}

template <typename T>
void Stack<T>::erase()
{
    delete [] this->data;
}

template <typename T>
void Stack<T>::resize()
{
    T* temp = new T[this->capacity * 2];
    for(size_t i = 0; i < this->size; ++i)
    {
        temp[i] = this->data[i];
    }
    this->erase();
    this->data = temp;
    this->capacity *= 2;
}

template <typename T>
Stack<T>::Stack(size_t initialCapacity) : size(0), capacity(initialCapacity) // data(nullptr) (?)
{
    this->data = new T[this->capacity];
}

template <typename T>
Stack<T>::Stack(const Stack<T>& other)
{
    this->copy(other);
}

template <typename T>
Stack<T>& Stack<T>::operator=(const Stack<T>& other)
{
    if(this != &other)
    {
        this->erase();
        this->copy(other);
    }
    return *this;
}

template <typename T>
Stack<T>::~Stack()
{
    this->erase();
}

template <typename T>
bool Stack<T>::isEmpty() const
{
    return this->size == 0;
}

template <typename T>
void Stack<T>::push(const T& element)
{
    if(this->size >= capacity)
    {
        this->resize();
    }
    data[this->size++] = element;
}

template <typename T>
T& Stack<T>::pop()
{
    if(isEmpty())
    {
        throw std::runtime_error("Cannot pop from an empty stack!");
    }
    return data[--this->size];
}

template <typename T>
size_t Stack<T>::getSize() const
{
    return this->size;
}
