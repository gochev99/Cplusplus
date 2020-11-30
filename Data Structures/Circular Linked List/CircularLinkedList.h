#pragma once
#include <stdexcept>

template <typename T>
struct Node
{
    T data;
    Node* next;

    Node(T data, Node* next = nullptr)
    {
        this->data = data;
        this->next = next;
    }
};


template <typename T>
class CircularList
{
private:
    Node<T>* first;
    Node<T>* last;
    size_t size;

    void copy(const CircularList&);
    void erase();
public:
    CircularList();
    CircularList(const CircularList&);
    CircularList& operator=(const CircularList&);
    ~CircularList();

    void push_back(const T&);
    void pop_front();
    void pop_after(Node<T>*);

    bool isEmpty() const;
    size_t getSize() const;
    Node<T>*& getFirst();
    Node<T>*& getLast();

    void print() const;
};

#include "CircularLinkedList.inl"
