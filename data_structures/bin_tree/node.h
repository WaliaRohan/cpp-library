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
        Node()
        {
            this->left = nullptr;
            this->right = nullptr;
            value = T();
        }

        /**
         * @brief Construct a new Node object with given left child node and right child node parameters
         * 
         * @param p_left left node parameter
         * @param p_right right node parameter
         */
        Node(Node* p_left, Node* p_right)
        {
            this->left = p_left;
            this->right = p_right;
            value = T();
        }

        /**
         * @brief Construct a new Node object with given left child node, right child node and node value parameter
         * 
         * @param p_left left node parameter
         * @param p_right right node parameter
         * @param p_value node value parameter
         */
        Node(Node* p_left, Node* p_right, T p_value)
        {
            this->left = p_left;
            this->right = p_right;
            this->value = p_value;
        }

        /**
         * @brief Set the value of this node
         * 
         * @param p_value Value to set the node value to
         */
        void setValue(const T& p_value)
        {
            this->value = p_value;
        }

        /**
         * @brief Get the value this node holds
         * 
         * @return T Value this node holds.
         */
        T getValue()
        {
            return this->value;
        }

        /**
         * @brief Compare current value with value of given node
         * 
         * @param p_node 
         * @return true 
         * @return false 
         */
        bool compareValue(Node* const p_node)
        {
            return p_node->value == this->value;
        }
        
        /**
         * @brief 
         * 
         * @param p_value 
         * @return true 
         * @return false 
         */
        bool compareValue(const T& p_value)
        {
            return p_value == this->value;
        }

    private:
        Node* left;
        Node* right;
        T value;
};

/// \todo Look into changing raw pointer usage to smart pointers
/// \todo Add getters and setters for child nodes
/// \todo add member intitializer lists for constructors