/**
 * @file bin_tree.h
 * @author Rohan Walia (walia.rohan@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-01-30
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef BIN_TREE_H
#define BIN_TREE_H

#include "node.h"

template <typename T>

class BinTree
{

public:
    /**
     * @brief Construct a new empty tree
     * 
     */
    BinTree::BinTree() : m_root{nullptr} {};

    /**
     * @brief Construct a new tree from the given root node
     * 
     * @param p_root 
     */
    BinTree::BinTree(Node<T> &p_root) : m_root{p_root} {};

private:
    Node<T> *m_root;
    int m_depth;
};

#endif