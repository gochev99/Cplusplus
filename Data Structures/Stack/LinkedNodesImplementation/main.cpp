#include <iostream>
#include "LinkedStack.h"


int main()
{
    Stack s1;
    std::cout << "Empty?: " <<  s1.isEmpty() << std::endl;
    s1.push(5);
    std::cout << "Empty?: " <<  s1.isEmpty() << std::endl;
    s1.pop();
    std::cout << "Empty?: " << s1.isEmpty() << std::endl;
    s1.push(1);
    std::cout << s1.top() << std::endl;
    s1.push(2);
    std::cout << s1.top() << std::endl;
    s1.push(3);
    std::cout << s1.top() << std::endl;
    s1.push(4);
    std::cout << s1.top() << std::endl;
    std::cout << "Size: " << s1.getSize() << std::endl;

    Stack s2(s1);
    std::cout << "*Stack 2*" << std::endl;
    std::cout << "Size: " << s2.getSize() << std::endl;
    std::cout << s2.top() << std::endl;
    s2.~Stack();
    std::cout << "Size: " << s2.getSize() << std::endl;



    return 0;
}
