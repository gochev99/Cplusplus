#include <iostream>
#include <string>
#include "CircularLinkedList.h"


// function prototypes
void mergeSort(Node<std::string>*& headRef);

Node<std::string>* sortedMerge(Node<std::string>* a, Node<std::string>* b);

void frontBackSplit(Node<std::string>* source, Node<std::string>*& frontRef, Node<std::string>*& backRef);

void sort(CircularList<std::string>&);


// main function to run the program
int main()
{
    CircularList<std::string> lst;
    std::string str;

    std::cout << "Enter a word or press CTRL+Z and then hit ENTER to stop entering!" << std::endl;
    while(std::cin >> str)
    {
        std::cout << "Enter another word or press CTRL+Z and then hit ENTER to stop entering!" << std::endl;
        lst.push_back(str);
    }
//    lst.print();
//    std::cout << std::endl;

    lst.wordGame(lst.getFirst());
    // In lexicographical sorting words starting with uppercase letter come first
    sort(lst);
    lst.print();
    std::cout << std::endl;
    std::cout << "Longest: " << lst.longestStr() << std::endl;

    return 0;
}


// function implementations
void sort(CircularList<std::string>& lst)
{
    lst.getLast()->next = nullptr;
    mergeSort(lst.getFirst());

    Node<std::string>* iter = lst.getFirst();
    while(iter->next != nullptr)
        iter = iter->next;

    lst.getLast() = iter;
    lst.getLast()->next = lst.getFirst();
}

void frontBackSplit(Node<std::string>* source, Node<std::string>*& frontRef, Node<std::string>*& backRef)
{
    Node<std::string>* fast = source->next;
    Node<std::string>* slow = source;

    while (fast != nullptr)
    {
        fast = fast->next;
        if (fast != nullptr)
        {
            slow = slow->next;
            fast = fast->next;
        }
    }

    frontRef = source;
    backRef = slow->next;
    slow->next = nullptr;
}

Node<std::string>* sortedMerge(Node<std::string>* a, Node<std::string>* b)
{
    Node<std::string>* result = nullptr;

    // base cases
    if (a == nullptr)
        return b;
    if (b == nullptr)
        return a;

    if (a->data.compare(b->data) <= 0)
    {
        result = a;
        result->next = sortedMerge(a->next, b);
    }
    else
    {
        result = b;
        result->next = sortedMerge(a, b->next);
    }
    return result;
}

void mergeSort(Node<std::string>*& headRef)
{
    Node<std::string>* head = headRef;
    Node<std::string>* a;
    Node<std::string>* b;

    if ((head == nullptr) || (head->next == nullptr))
    {
        return;
    }

    frontBackSplit(head, a, b);

    mergeSort(a);
    mergeSort(b);

    headRef = sortedMerge(a, b);
}
