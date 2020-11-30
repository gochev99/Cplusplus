#pragma once
#include<iostream>

typedef int T;
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


class Stack
{
private:
    Node* tos;
    size_t size;

    void copy(const Stack& other);
    void clear();
public:
    Stack();
    Stack(const Stack& other);
    Stack& operator=(const Stack& other);
    ~Stack();

    void push(const T& element);
    void pop();
    T& top();
    const T& top() const;
    size_t getSize() const;
    bool isEmpty() const;
};
