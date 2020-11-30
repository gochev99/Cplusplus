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
class List
{
private:
    Node<T>* first;
    Node<T>* last;
    size_t size;

    void copy(const List&);
    void erase();
public:
    List();
    List(const List&);
    List& operator=(const List&);
    ~List();

    void push_back(const T&);
    void push_front(const T&);
    void push_after(Node<T>*, const T&);
    void pop_back();
    void pop_front();
    void pop_after(Node<T>*);

    bool isEmpty() const;
    size_t getSize() const;
    T& getFirst();
    const T& getFirst() const;
    T& getLast();
    const T& getLast() const;

    void print() const;
};

#include "LinkedList.inl"
