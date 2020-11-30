#include "LinkedStack.h"

void Stack::copy(const Stack& other)
{
    this->size = other.size;
    this->tos = new Node(other.tos->data);
    Node* cpy = this->tos;
    Node* orig = other.tos->next;
    while(orig)
    {
        cpy->next = new Node(orig->data);
        cpy = cpy->next;
        orig = orig->next;
    }
}


void Stack::clear()
{
//    Node* tmp;
//    while(this->tos)
//    {
//        tmp = this->tos;
//        this->tos = this->tos->next;
//        delete tmp;
//    }
//    this->tos = nullptr;
//    this->size = 0;

    while(!isEmpty())
    {
        this->pop();
    }
}

Stack::Stack() : tos(nullptr), size(0) {}

Stack::Stack(const Stack& other) {this->copy(other);}

Stack& Stack::operator=(const Stack& other)
{
    if(this != &other)
    {
        this->clear();
        this->copy(other);
    }
    return *this;
}

Stack::~Stack(){this->clear();}

void Stack::push(const T& data)
{
    this->tos = new Node(data, this->tos);
    ++size;
}

void Stack::pop()
{
    if(isEmpty())
    {
        std::runtime_error("Cannot pop from an empty stack!");
    }
    Node* tmp = this->tos;
    this->tos = this->tos->next;
    delete tmp;
    --size;
}

T& Stack::top()
{
    if(isEmpty())
    {
        std::runtime_error("Cannot peek in an empty stack!");
    }
    return this->tos->data;
}

const T& Stack::top() const
{
    if(isEmpty())
    {
        std::runtime_error("Cannot peek in an empty stack!");
    }
    return this->tos->data;
}

size_t Stack::getSize() const
{
    return this->size;
}

bool Stack::isEmpty() const
{
    return this->size == 0;
}
