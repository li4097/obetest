/*
 * rbtree.h
 * Copyright (C) 2019 LQ <LQ@localhost.localdomain>
 *
 * Distributed under terms of the MIT license.
 */

#ifndef RBTREE_H
#define RBTREE_H
#include "utility.h"

enum RBNodeColer{
    RED,
    BLACK
};

template<class T>
struct RBNode
{
    T data;
    RBNode* left;
    RBNode* right;
    RBNodeColer color;
};

template<class T>
class RBTree
{
public:
    RBTree()
        :head(nullptr),
        size(0)
    {}
    ~RBTree()
    {}
private:
    RBNode<T>* _RotateLeft(RBNode<T>* n)
    {
        if(nullptr == n || nullptr == n->right)
        {
            return n;
        }
        RBNode<T>* tmp = n->right;
        n->right = tmp->left;
        tmp->left = n;
        tmp->color = n->color;
        n->color = RED;

        return tmp;
    } 

    RBNode<T>* _RotateRight(RBNode<T>* n)
    {
        if(nullptr == n || nullptr == n->left)
        {
            return n;
        }
        RBNode<T>* tmp = n->left;
        n->left = tmp->right;
        tmp->right = n;
        tmp->coloer = n->color;
        n->color = REA;

        return tmp;
    }

    RBNode<T>* _Insert(RBNode<T>* n,T data)
    {
        if(nullptr == n)
        {
            n = new RBNode<T>;
            n->data = data;
            n->left = n->right = nullptr;

            return n;
        }
        if(n->data > data)
        {
            n->left = _Insert(n->left,data);
        }
        else if(n->data < data)
        {
            n->right = _Insert(n->right,data);
        }
        else 
        {
            return n;
        }

        if(nullptr != n)
        {
            
        }

    }
private:
    RBNode* head;
    uint32_t size;
};
#endif /* !RBTREE_H */
