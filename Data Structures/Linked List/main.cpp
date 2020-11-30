#include <iostream>
#include "LinkedList.h"


int main()
{
    List<int> lst1;
    std::cout << "Empty?: " <<  lst1.isEmpty() << std::endl;
    lst1.push_front(5);
    std::cout << "Empty?: " <<  lst1.isEmpty() << std::endl;
    lst1.pop_back();
    std::cout << "Empty?: " << lst1.isEmpty() << std::endl;
    lst1.push_front(1);
    std::cout << lst1.getFirst() << std::endl;
    lst1.push_back(2);
    std::cout << lst1.getLast() << std::endl;
    lst1.push_back(3);
    std::cout << lst1.getLast() << std::endl;
    lst1.push_back(4);
    std::cout << lst1.getLast() << std::endl;
    std::cout << "Size: " << lst1.getSize() << std::endl;

    List<int> lst2(lst1);
    std::cout << "*List 2*" << std::endl;
    std::cout << "Size: " << lst2.getSize() << std::endl;
    std::cout << lst2.getFirst() << std::endl;
    std::cout << lst2.getLast() << std::endl;
    lst2.~List();
    std::cout << "Size: " << lst2.getSize() << std::endl;


    return 0;
}
