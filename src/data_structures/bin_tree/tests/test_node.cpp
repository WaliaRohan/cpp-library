/**
 * @file test_node.cpp
 * @author Rohan Walia (walia.rohan@gmail.com)
 * @brief Test cases for checking functionality of node class
 * @version 0.1
 * @date 2022-01-29
 * 
 * @copyright Copyright (c) 2022
 * 
 */

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

/**
 * @brief Checks that an node value is empty when not specified through constructor
 * 
 */
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

/**
 * @brief Construct a new TEST object
 * 
 */
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

/**
 * @brief Checks node comparison functionality (two nodes are equal when they have the same child nodes and values)
 * 
 */
TEST(NodeInitTest, CompareGivenNode)
{
    Node<int> left_child;
    Node<int> right_child;
    Node<int> parent_node(&left_child, &right_child, 1);

    Node<int> duplicate(parent_node);

    ASSERT_EQ(true, parent_node.compareNode(duplicate));
}

/**
 * @brief Checks whether a node holds a particular value
 * 
 */
TEST(NodeInitTest, CompareGivenValue)
{
    Node<int> left_child;
    Node<int> right_child;
    Node<int> parent_node(&left_child, &right_child, 1);

    ASSERT_EQ(true, parent_node.compareValue(1));
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS(); // Macro for running all tests
}