#include <iostream>

#include "node.h"

int main()
{
    Node<int>* leftChildNode;
    Node<int>* rightChildNode;

    int value = 47;

    Node<int> integerNode;

    std::cout << integerNode.getValue() << std::endl;  
    
    integerNode = Node<int>(leftChildNode, rightChildNode, value);

    std::cout << integerNode.getValue() << std::endl;  

    integerNode.setValue(22);

    std::cout << integerNode.getValue() << std::endl;  

    return 0;
}