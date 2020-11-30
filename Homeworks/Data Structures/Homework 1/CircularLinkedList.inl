#pragma once


template <typename T>
void CircularList<T>::copy(const CircularList& other)
{
    Node<T>* it = other.first;
    if(it != nullptr)
    {
        do
        {
            push_back(it->data);
            it = it->next;
        }
        while(it != other.first);
    }
}

template <typename T>
void CircularList<T>::erase()
{
    while(!isEmpty())
    {
        pop_front();
    }
}

template <typename T>
CircularList<T>::CircularList() : first(nullptr), last(nullptr), size(0) {}

template <typename T>
CircularList<T>::CircularList(const CircularList& other)
{
    copy(other);
}

template <typename T>
CircularList<T>& CircularList<T>::operator=(const CircularList& other)
{
    if(this != &other)
    {
        erase();
        copy(other);
    }
    return *this;
}

template <typename T>
CircularList<T>::~CircularList()
{
    erase();
}

template <typename T>
void CircularList<T>::push_back(const T& data)
{
    Node<T>* newNode = new Node<T>(data);
    if(isEmpty())
    {
        first = last = newNode;
        last->next = first;
    }
    else
    {
        last->next = newNode;
        last = newNode;
        newNode->next = first;
    }
    size++;
}

template <typename T>
void CircularList<T>::pop_front()
{
    if(isEmpty())
    {
        throw std::runtime_error("Cannot pop from an empty list");
    }
    if(first->next == first)
    {
        delete first;
        first = last = nullptr;
    }
    else
    {
        Node<T>* tmp = first;
        first = first->next;
        last->next = first;
        delete tmp;
    }
    size--;
}

template <typename T>
void CircularList<T>::pop_after(Node<T>* iter)
{
    if(iter == nullptr)
    {
        throw std::invalid_argument("Invalid node to pop after!");
    }
    if(size == 1)
    {
        delete first;
        first = nullptr;
        last = nullptr;
        size--;
        return;
    }
    if(iter->next == first)
    {
        first = first->next;
    }
    if(iter->next == last)
    {
        last = iter;
    }
    Node<T>* tmp = iter->next;
    iter->next = iter->next->next;
    delete tmp;
    size--;
}

template <typename T>
bool CircularList<T>::isEmpty() const
{
    return size == 0;
}

template <typename T>
size_t CircularList<T>::getSize() const
{
    return size;
}

template <typename T>
Node<T>*& CircularList<T>::getFirst()
{
    if(isEmpty())
    {
        throw std::runtime_error("List is empty, cannot get first!");
    }
    return first;
}

template <typename T>
Node<T>*& CircularList<T>::getLast()
{
    if(isEmpty())
    {
        throw std::runtime_error("List is empty, cannot get last!");
    }
    return last;
}

template <typename T>
void CircularList<T>::print() const
{
    if(isEmpty())
        std::cout << "Empty list printed.";
    Node<T>* it = first;
    if(first != nullptr)
    {
        std::cout << "-> ";
        do
        {
            std::cout << it->data << " -> ";
            it = it->next;
        }
        while(it != first);
    }
}



// ----------------------------------------------------------------------------------------------------------------------------------------
// new functions
template <>
void CircularList<std::string>::wordGame(Node<std::string>* head)
{
    Node<std::string>* iter = head;
    bool flag = true;

    do
    {
        if(size == 1)
            return;
        if(iter == first->next)
        {
            flag = false;
        }
        if(tolower(iter->data.at(iter->data.length() - 1)) == tolower(iter->next->data.at(0)))
        {
            iter->data += '-';
            iter->data += iter->next->data;
            pop_after(iter);
        }
        else
        {
            iter = iter->next;
        }
    }
    while(flag || iter != first);
}

template <>
std::string CircularList<std::string>::longestStr()
{
    Node<std::string>* iter = first;
    std::string longest = first->data;
    do
    {
        if(longest.length() < iter->data.length())
            longest = iter->data;
        iter = iter->next;
    }
    while(iter != first);

    return longest;
}
