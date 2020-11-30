#pragma once

template <typename T>
void List<T>::copy(const List<T>& other)
{
    Node<T>* it = other.first;
    while(it)
    {
        this->push_back(it->data);
        it = it->next;
    }
}

template <typename T>
void List<T>::erase()
{
    while(!isEmpty())
    {
        pop_front();
    }

//    while(this->first)
//    {
//        Node<T>* tmp = this->first;
//        this->first = this->first->next;
//        delete tmp;
//    }
//    this->size = 0;
}


template <typename T>
List<T>::List() : first(nullptr), last(nullptr), size(0) {};

template <typename T>
List<T>::List(const List<T>& other)
{
    this->copy(other);
}

template <typename T>
List<T>& List<T>::operator=(const List<T>& other)
{
    if(this != &other)
    {
        this->erase();
        this->copy(other);
    }
    return *this;
}

template <typename T>
List<T>::~List()
{
    this->erase();
}


template <typename T>
void List<T>::push_back(const T& data)
{
    Node<T>* newNode = new Node<T>(data);
    if(isEmpty())
    {
        this->first = this->last = newNode;
    }
    else
    {
        this->last->next = newNode;
        this->last = newNode;
    }
    this->size++;
}

template <typename T>
void List<T>::push_front(const T& data)
{
    Node<T>* newNode = new Node<T>(data);
    if(isEmpty())
    {
        this->first = this->last = newNode;
    }
    else
    {
        newNode->next = first;
        first = newNode;
    }
    this->size++;
}

template <typename T>
void List<T>::push_after(Node<T>* iter, const T& data)
{
    if(iter != nullptr)
    {
        Node<T>* newNode = new Node<T>(data, iter->next);
        iter->next = newNode;
        this->size++;
        if(iter == this->last)
        {
            this->last = newNode;
        }
    }
    else
    {
        throw std::invalid_argument("Illegal node!");
    }
}

template <typename T>
void List<T>::pop_back()
{
    if(isEmpty())
    {
        throw std::runtime_error("Cannot pop from an empty list");
    }
    if(this->first->next == nullptr)
    {
        delete this->first;
        this->first = this->last = nullptr;
    }
    else
    {
        Node<T>* it = this->first;
        while(it->next != this->last)
        {
            it = it->next;
        }
        it->next = nullptr;
        Node<T>* tmp = this->last;
        this->last = it;
        delete tmp;
    }
    this->size--;
}

template <typename T>
void List<T>::pop_front()
{
    if(isEmpty())
    {
        throw std::runtime_error("Cannot pop from an empty list");
    }
    if(this->first->next == nullptr)
    {
        delete this->first;
        this->first = this->last = nullptr;
    }
    else
    {
        Node<T>* tmp = this->first;
        this->first = this->first->next;
        delete tmp;
    }
    this->size--;
}

template <typename T>
void List<T>::pop_after(Node<T>* iter)
{
    if(iter != nullptr)
    {
        if(iter == this->last)
        {
            throw std::logic_error("Cannot pop after last!");
        }
        if(iter->next == this->last)
        {
            this->last = iter;
        }
        Node<T>* tmp = iter->next;
        iter->next = iter->next->next;
        delete tmp;
        this->size--;
    }
    else
    {
        throw std::invalid_argument("Illegal value!");
    }
}

template <typename T>
bool List<T>::isEmpty() const
{
    return this->size == 0;
}

template <typename T>
size_t List<T>::getSize() const
{
    return this->size;
}

template <typename T>
T& List<T>::getFirst()
{
    if(isEmpty())
    {
        throw std::runtime_error("List is empty, cannot get!");
    }
    return this->first->data;
}

template <typename T>
const T& List<T>::getFirst() const
{
    if(isEmpty())
    {
        throw std::runtime_error("List is empty, cannot get!");
    }
    return this->first->data;
}

template <typename T>
T& List<T>::getLast()
{
    if(isEmpty())
    {
        throw std::runtime_error("List is empty, cannot get!");
    }
    return this->last->data;
}

template <typename T>
const T& List<T>::getLast() const
{
    if(isEmpty())
    {
        throw std::runtime_error("List is empty, cannot get!");
    }
    return this->last->data;
}

template <typename T>
void List<T>::print() const
{
    Node<T>* it = this->first;
    while(it)
    {
        std::cout << it->data << " ";
        it = it->next;
    }
    std::cout << std::endl;
}
