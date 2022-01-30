#include <iostream>

#include "../node.h"
#include <gtest/gtest.h>

// Node initialization tests

/**
 * @brief Checks that an empty node is created properly with left 
 *        and right child nodes being null pointers and value being 0
 * 
 */
TEST(NodeInitTest, EmptyNode) { 
    Node<int> empty_node;
    ASSERT_EQ(nullptr, empty_node.getLeft());
    ASSERT_EQ(nullptr, empty_node.getRight());
    ASSERT_EQ(0, empty_node.getValue());
}

TEST(NodeInitTest, EmptyValue) { 
    Node<int> left_child;
    Node<int> right_child;
    Node<int> parent_node(&left_child, &right_child);

    // Make sure parent nodes left and right children are not null pointers
    ASSERT_NE(nullptr, parent_node.getLeft());
    ASSERT_NE(nullptr, parent_node.getRight());

    // Parent should have '0' value
    ASSERT_EQ(0, parent_node.getValue());
}

TEST(NodeInitTest, FullyInializedNode) { 
    Node<int> left_child;
    Node<int> right_child;
    Node<int> parent_node(&left_child, &right_child, 1);

    // Make sure parent nodes left and right children are not null pointers
    ASSERT_NE(nullptr, parent_node.getLeft());
    ASSERT_NE(nullptr, parent_node.getRight());

    // Parent should have '1' value
    ASSERT_EQ(1, parent_node.getValue());
}
 
// Node value comparison tests

TEST(NodeInitTest, CompareGivenNode)
{
    Node<int> left_child;
    Node<int> right_child;
    Node<int> parent_node(&left_child, &right_child, 1);

    Node<int> duplicate(parent_node);

    ASSERT_EQ(true, parent_node.compareNode(duplicate));
}

TEST(NodeInitTest, CompareGivenValue)
{
    Node<int> left_child;
    Node<int> right_child;
    Node<int> parent_node(&left_child, &right_child, 1);

    ASSERT_EQ(true, parent_node.compareValue(1));
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

// int main()
// {
//     Node<int>* leftChildNode;
//     Node<int>* rightChildNode;

//     int value = 47;

//     Node<int> integerNode;

//     std::cout << integerNode.getValue() << std::endl;  
    
//     integerNode = Node<int>(leftChildNode, rightChildNode, value);

//     std::cout << integerNode.getValue() << std::endl;  

//     integerNode.setValue(22);

//     std::cout << integerNode.getValue() << std::endl;  

//     std::cout << (integerNode.getLeft() == leftChildNode) << std::endl;
//     std::cout << (integerNode.getRight() == rightChildNode) << std::endl;

//     return 0;
// }