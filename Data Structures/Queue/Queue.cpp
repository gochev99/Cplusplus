#include "Queue.h"
#include <stdexcept>

Node* Queue::copyNode(const Node* n)
{
    if(n)
    {
        Node* newNode = new Node(n->data);
        return newNode;
    }
    throw std::runtime_error("Cannot copy a nullptr node!");
}

void Queue::copy(const Queue& other)
{
    this->front = copyNode(other.front);
    Node* orig = other.front;
    Node* cpy = this->front;
    while(orig->next)
    {
        cpy->next = copyNode(orig->next);
        orig = orig->next;
        cpy = cpy->next;
    }
    this->back = copyNode(other.back);
}

void Queue::clear(Node* n)
{
    while(n)
    {
        Node* tmp = n;
        n = n->next;
        delete tmp;
    }
}

Queue::Queue(): front(nullptr), back(nullptr), count(0) {}

Queue::Queue(const Queue& other)
{
    copy(other);
}


Queue& Queue::operator=(const Queue& other)
{
    if(this != &other)
    {
        clear(this->front);
        copy(other);
    }
    return *this;
}


Queue::~Queue()
{
    this->clear(this->front);
}

void Queue::enqueue(const T& data)
{
    Node* n = new Node(data);
    if(!isEmpty())
    {
        this->back->next = n;
    }
    else
    {
        this->front = n;
    }
    this->back = n;
    ++count;
}

T Queue::dequeue()
{
    if(isEmpty())
    {
        throw std::logic_error("Cannot dequeue from an empty queue!");

    }
    Node* tmp = this->front;
    this->front = tmp->next;
    T x = tmp->data;
    delete tmp;
    --count;

    return x;
}

T& Queue::getFront() const
{
    if(isEmpty())
    {
        throw std::logic_error("Cannot get front, queue is empty!");

    }
    return this->front->data;
}


bool Queue::isEmpty() const
{
    return this->front == nullptr;
}


size_t Queue::size() const
{
    return this->count;
}

