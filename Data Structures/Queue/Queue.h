#pragma once
#include <cstddef>

typedef char T;
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

class Queue
{
private:
    Node* front;
    Node* back;
    size_t count;

    Node* copyNode(const Node* n);
    void copy(const Queue& other);
    void clear(Node* n);
public:
    Queue();
    Queue(const Queue& other);
    Queue& operator=(const Queue& other);
    ~Queue();

    void enqueue(const T& data);
    T dequeue();
    T& getFront() const;

    bool isEmpty() const;
    size_t size() const;
};
