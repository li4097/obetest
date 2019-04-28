/*
 * rbtree.h
 * Copyright (C) 2019 LQ <LQ@localhost.localdomain>
 *
 * Distributed under terms of the MIT license.
 */

#ifndef RBTREE_H
#define RBTREE_H
#include "utility.h"

#define RED true
#define BLACK false

template<class T>
struct RBNode
{
    T data;
    RBNode* left;
    RBNode* right;
    bool color;
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
    void Insert(T data)
    {
        head = _Insert(head,data);
        head->color = BLACK;
    }
private:
    

    RBNode<T>* _Insert(RBNode<T>* n,T data)
    {
        if (nullptr == n)
        {
            n = new RBNode<T>;
            n->data = data;
            n->left = n->right = nullptr;
            n->color = RED;

            size++;
            return n;
        }

        if(data < n->data)
        {
            n->left = _Insert(n->left,data);
        }
        else if(data > n->data)
        {
            n->right = _Insert(n->right,data);
        }
        else
        {
            return n;
        }

        if(!_IsRed(n->left) && _IsRed(n->right))
        {
            n = _RotateLeft(n);
        }

        if(_IsRed(n->left) && _IsRed(n->left->left))
        {
            n = _RotateRight(n);
        }

        if(_IsRed(n->left) && _IsRed(n->right))
        {
            n = _FlipColor(n);
        }

    }
    inline bool _IsRed(RBNode<T>* n)
    {
        return (nullptr == n) ? false : n->color;  
    }
    inline RBNode<T>* _FlipColor(RBNode<T>* n)
    {
        n->left->color = !n->left->color;
        n->right->color = !n->right->color;
        n->color = !n->color;

        return n;
    }
    inline RBNode<T>* _RotateLeft(RBNode<T>* n)
    {
        if(nullptr == n || nullptr == n->right)
        {
            return n;
        }
        RBNode<T>* tmp = n->right;
        n->right = tmp->left;
        tmp->left = n;
        n->parent = tmp;
        tmp->color = n->color;
        n->color = RED;

        return tmp;
    } 

    inline RBNode<T>* _RotateRight(RBNode<T>* n)
    {
        if(nullptr == n || nullptr == n->left)
        {
            return n;
        }
        RBNode<T>* tmp = n->left;
        n->left = tmp->right;
        tmp->right = n;
        tmp->coloer = n->color;
        n->color = RED;

        return tmp;
    }
private:
    RBNode<T>* head;
    uint32_t size;
};
#endif /* !RBTREE_H */
