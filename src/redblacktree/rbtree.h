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
        head = _insert(head,data);
        head->color = BLACK;
    }
    void DeleteMax()
    {
        head = _deleteMax(head);
        head->color = BLACK;
    }
private:
    

    RBNode<T>* _insert(RBNode<T>* n,T data)
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
            n->left = _insert(n->left,data);
        }
        else if(data > n->data)
        {
            n->right = _insert(n->right,data);
        }
        else
        {
            return n;
        }

        return _fixUp(n);

    }
    RBNode<T>* _deleteMax(RBNode<T>* n)
    {
        if(nullptr == n)
        {
            return n;
        }
        if(true == _isRed(n->left))
        {
            //将3节点的左倾改为右倾
            _rotateRight(n);
        }
        if(nullptr == n->right) 
        //此时 n->left 必为nullptr
        //因为如果此时不为nullptr，则表示删除之前最大值不在最底层，经分析，这是不可能的
        {
            //删除最大节点
            delete n;
            return nullptr;
        }

        n = _moveRedRightIfNecessary(n);

        n->right = _deleteMax(n->right);

        return _fixUp(n);
    }

    RBNode<T>* _deleteMin(RBNode<T>* n)
    {
        if(nullptr == n)
        {
            return n;
        }
        if(nullptr == n->left)
        {
            //删除最小节点
            delete n;
            retrun nullptr;
        }

        n = _moveRedLeftIfNecessary(n);

        n->left = _deleteMin(n->left);

        _fixUp(n);
    }
    
    RBNode<T>* _delete(RBNode<T>* n,T data)
    {
        if(nullptr == n)
        {
            return n;
        }
        if(data < n->data)
        {
            n = _moveRedLeftIfNecessary(n);
            n->left = _delete(n->left);
        }
        else
        {
            if(true == _isRed(n->left))
            {
                 n = _rotateRight(n);
            }
            if(data == n->data && nullptr == n->right)
            {
                delete n;
                return nullptr;
            }
            n = _moveRedRightIfNecessary(n);
            if(data == n->data)
            {
                 RBNode<T>* min = _findMin(n->right);
                 if(nullptr != min)
                 {
                     n->data = min->data;
                     n->right = _deleteMin(n->right);
                 }
            }
            else
            {
                n->right = _delete(n->right,data);
            }
        }

        return _fixUp(n);
    }

    

    inline RBNode<T>* _findMin(RBNode<T>* n)
    {
        if(nullptr == n || nullptr == n->left)
        {
            return n; 
        }
        while(nullptr != n->left)
        {
            n = n->left;
        }
        return n;
    }
    //将n修正为左倾红黑树
    RBNode<T>* _fixUp(RBNode<T>* n)
    {
        if(nullptr == n)
        {
            return n;
        }
        if(!_isRed(n->left) && _isRed(n->right))
        {
            n = _rotateLeft(n);
        }

        if(_isRed(n->left) && _isRed(n->left->left))
        {
            n = _rotateRight(n);
        }

        if(_isRed(n->left) && _isRed(n->right))
        {
            n = _flipColor(n);
        }

        return n;
    }

    inline bool _isRed(RBNode<T>* n)
    {
        return (nullptr == n) ? false : n->color;  
    }
    inline RBNode<T>* _flipColor(RBNode<T>* n)
    {
        if(nullptr != n)
        {
            n->color = !n->color;
            if(nullptr != n->left)
            {
                n->left->color = !n->left->color;
            }
            if(nullptr != n->right)  
            {
                n->right->color = !n->right->color; 
            }
        }

        return n;
    }
    inline RBNode<T>* _rotateLeft(RBNode<T>* n)
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

    inline RBNode<T>* _rotateRight(RBNode<T>* n)
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


    //若n->left及n->left->left都为黑，则表示n->left为2节点,借一个节点成为3节点
    RBNode<T>* _moveRedLeftIfNecessary(RBNode<T>* n)
    {
        if(nulllptr != n &&
            false == _isRed(n->left) && 
                false == _isRed(n->left->left))
        {
            n = _moveRedLeft(n);
        }

        return n;
    }

    
    //若n->right及n->right->left都为黑，则表示n->right为2节点,借一个节点成为3节点
    RBNode<T>* _moveRedRightIfNecessary(RBNode<T>* n)
    {
        if(nullptr != n &&
            false == _isRed(n->right) && 
                false == _isRed(n->right->left))
        {
            n = _moveRedRight(n);
        }

        return n;
    }
    //删除操作中，如果右节点为2节点，则需要从父节点或兄弟节点借一个节点，成为3节点
    RBNode<T>* _moveRedRight(RBNode<T>* n)
    {
        
        _flipColor(n);//从父节点借一个节点，成为3节点
        if(true == _isRed(n->left->left))
        {
            // 如果兄弟节点是3或4节点，则从兄弟节点借一个节点，成为3节点
            n = _rotateRight(n);
            _flipColor(n);
        }
    }
    
    //删除操作中，如果左节点为2节点，则需要从父节点或兄弟节点借一个节点，成为3节点
    RBNode<T>* _moveRedLeft(RBNode<T>* n)
    {
        
        _flipColor(n);//从父节点借一个节点，成为3节点
        if(true == _isRed(n->right->left))
        {
            // 如果兄弟节点是3或4节点，则从兄弟节点借一个节点，成为3节点
            n->right = _rotateRight(n->right);
            n = _rotateLeft(n);
            _flipColor(n);
        }
    }
private:
    RBNode<T>* head;
    uint32_t size;
};
#endif /* !RBTREE_H */
