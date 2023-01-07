/**
 * @file node.h
 * @author Rohan Walia (walia.rohan@gmail.com)
 * @brief Class definition for implementing node in a tree data structure.
 * @version 0.1
 * @date 2022-01-29
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef NODE_H
#define NODE_H

/**
 * @brief Template for object type of node value
 * 
 * @tparam T 
 */
template <typename T>

/**
 * @brief Implements a node for a binary search tree such that it holds pointers to two children (left and right) and its current value 
 * 
 */
class Node
{
    public:

        /**
         * @brief Construct a new Node object
         * 
         */
        Node() : m_left{nullptr}, m_right{nullptr}, m_value{T()} {}

        /**
         * @brief Construct a new Node object with given left child node and right child node parameters
         * 
         * @param p_left left node parameter
         * @param p_right right node parameter
         */
        Node(Node* p_left, Node* p_right) : m_left{p_left}, m_right{p_right}, m_value{T()} {}

        /**
         * @brief Construct a new Node object with given left child node, right child node and node value parameter
         * 
         * @param p_left left node parameter
         * @param p_right right node parameter
         * @param p_value node value parameter
         */
        Node(Node* p_left, Node* p_right, T p_value) : m_left{p_left}, m_right{p_right}, m_value{p_value} {}


        /**
         * @brief Set the left child node
         * 
         * @param p_node 
         */
        void setLeft(Node<T>& p_node) 
        { 
            this->m_left = &p_node;
        };

        /**
         * @brief Set the right child node
         * 
         * @param p_node 
         */
        void setRight(Node<T>& p_node) 
        { 
            this->m_right = &p_node;
        };

        /**
         * @brief Set the value of this node
         * 
         * @param p_value Value to set the node value to
         */
        void setValue(const T& p_value)
        {
            this->m_value = p_value;
        }

        /**
         * @brief Return the left child node of this node
         * 
         * @return left child node of this node
         */
        Node<T>* getLeft() { return this->m_left; }


        /**
         * @brief Return the right child node of this node
         * 
         * @return right child node of this node
         * 
         */
        Node<T>* getRight() { return this->m_right; }

        /**
         * @brief Get the value this node holds
         * 
         * @return T Value this node holds.
         */
        T getValue() { return this->m_value; }

        /**
         * @brief Compare current children nodes and value with those of given node
         * 
         * @param p_node The given node
         * @return true If the children nodes and the value are same
         * @return false If either left or right child or value are not the same
         */
        bool compareNode(Node& p_node)
        {
            return (p_node.getLeft() == this->m_left &&
                    p_node.getRight() == this->m_right && 
                    p_node.getValue() == this->m_value);
        }
        
        /**
         * @brief Compare the value this node holds with the given value
         * 
         * @param p_value Given value to compare to
         * @return true If this node's value is equal to the given value
         * @return false  If this node's value is not equal to the given value
         */
        bool compareValue(const T& p_value)
        {
            return p_value == this->m_value;
        }

        /**
         * @brief Check if this node is a leaf node
         * 
         * @return true If the left and right children are null pointers
         * @return false If either the left or the right child is not a null pointer
         */
        bool isLeaf()
        {
            return (m_left == nullptr && m_right == nullptr);
        }

    private:
        Node* m_left;
        Node* m_right;
        T m_value;
};

#endif

/// \todo Look into changing raw pointer usage to smart pointers