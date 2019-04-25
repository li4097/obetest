/*
 * avltree.h
 * Copyright (C) 2019 LQ <LQ@localhost.localdomain>
 *
 * Distributed under terms of the MIT license.
 */

#ifndef AVLTREE_H
#define AVLTREE_H

#include "utility.h"
#include "binarytree.h"

#define MAX(x,y) ((x) > (y) ? (x) : (y))
template<class T>
class AVLTree
{
public:
	AVLTree()
	:head(nullptr),
		size(0)
	{}
	~AVLTree()
	{};

	void Insert(const T& data)
	{
        _Insert(head,data);
	}
	void Delete(const T& data)
	{
        _Remove(head,data);
	}
    
    Node<T>* GetHead()
    {
        return head;
    }
    uint32_t GetSize()
    {
        return size;
    }
private:

    
    inline uint8_t _GetHeight(Node<T>* n1)
    {
        if(n1)
        {
            return n1->height;
        }
        return 0;
    }
    inline void _SetHeight(Node<T>* n)
    {
        if(n)
        {
            uint8_t byLeft = _GetHeight(n->left);
            uint8_t byRight = _GetHeight(n->right);
            n->height = MAX(byLeft,byRight) + 1;
        }
    }
    //左左 单旋右旋
    Node<T>* _singleRotateWithRight(Node<T>* t)
    {
        if(nullptr == t || nullptr == t->left)
        {
            return t;
        }
        Node<T>* tmp = t->left;
        t->left = tmp->right;
        tmp->right = t;

        _SetHeight(t);
        _SetHeight(tmp);

        return tmp;
    }
    //右右 单旋左旋
    Node<T>* _singleRotateWithLeft(Node<T>* t)
    {
        if(nullptr == t || nullptr == t->right)
        {
            return t;
        }
        Node<T>* tmp = t->right;
        t->right = tmp->left;
        tmp->left = t;

        _SetHeight(t);
        _SetHeight(tmp);
        
        return tmp;
    }
    //左右 先左后右
    Node<T>* _doubleRotateWithLeftRight(Node<T>* t)
    {
        if(nullptr == t)
        {
            return t;
        }
        t->left = _singleRotateWithLeft(t->left);
        t =  _singleRotateWithRight(t);

        return t;
    }
    //右左 先右后左
    Node<T>* _doubleRotateWithRightLeft(Node<T>* t)
    {
        if(nullptr == t)
        {
            return t;
        }
        t->right = _singleRotateWithRight(t->right);
        t =  _singleRotateWithLeft(t);

        
        return t;
    }
    Node<T>* _Insert(Node<T>* & t,T data)
    {
        if(nullptr == t)
        {
            t = new Node<T>(data);
            t->data = data;
            t->left = nullptr;
            t->right = nullptr;
            t->height = 1;
            size++;
        }
        else
        {
            if(t->data > data)
            {
                t->left = _Insert(t->left,data);
                if(t->left)
                {
                    //高度差不会超过2
                    if(2 == _GetHeight(t->left) - _GetHeight(t->right))
                    {
                        //不会出现 data == t->left->data的情况
                        if(t->left->data > data)
                        {
                            t = _singleRotateWithRight(t);
                        }
                        else
                        {
                            t = _doubleRotateWithLeftRight(t);
                        }
                    }
                }
            }
            else if(t->data < data)
            {
                t->right = _Insert(t->right,data);
                if(t->right)
                {
                    //高度差不会超过2
                    if(2 == _GetHeight(t->right) - _GetHeight(t->left))
                    {
                        //不会出现 data == t->right->data的情况
                        if(t->right->data < data)
                        {
                            t = _singleRotateWithLeft(t);
                        }
                        else
                        {
                            t = _doubleRotateWithRightLeft(t);
                        }
                    }
                }
            }
            _SetHeight(t);
        }
        return t;
    }
    Node<T>* _Remove(Node<T>* & t,T data)
    {
        if (nullptr == t)
        {
            return t;
        }
        if(t->data > data)
        {
            t->left = _Remove(t->left,data);
            //高度差不会超过2
            if(2 == _GetHeight(t->right) - _GetHeight(t->left))
            {
                t = _singleRotateWithLeft(t);
            }
        }
        else if(t->data < data)
        {
            t->right = _Remove(t->right,data);
            //高度差不会超过2
            if(2 == _GetHeight(t->left) - _GetHeight(t->right))
            {
                t = _singleRotateWithRight(t);
            }
        }
        else 
        {
            if(nullptr == t->left && nullptr == t->right)
            {
                delete t;
                t = nullptr;
            }
            else if(_GetHeight(t->left) >= _GetHeight(t->right))
            {
                //此时t->left必不为nullptr
                Node<T>* tmp = t->left;
                if(nullptr == tmp->right)
                {
                    //tmp没有右子树，则左子树若存在必为叶子节点
                    tmp->right = t->right;
                    delete t;
                    t = tmp;
                }
                else
                {   
                    Stack<Node<T>*> s;//用以记录tmp->right沿线的右节点，方便后续旋转
                    s.Push(tmp);
                    //左子树的最大右叶子节点代替t的位置 
                    while(nullptr != tmp->right->right)
                    {
                        tmp = tmp->right;
                        s.Push(tmp);
                    }
                    Node<T>* rtn = tmp->right;
                    tmp->right = rtn->left;
                    tmp = s.Pop();
                    while(nullptr != tmp)
                    {
                        _SetHeight(tmp);
                        tmp = s.Pop();
                    }
                    rtn->left = t->left;
                    rtn->right = t->right;
                    
                    delete t;
                    t = rtn;
                }
            }
            else
            {
                //_GetHeight(t->left) < _GetHeight(t->right)
                //此时t->right必不为nullptr
                Node<T>* tmp = t->right;
                if(nullptr == tmp->left)
                {
                    //tmp没有左子树，则右子树若存在必为叶子节点
                    tmp->left = t->left;
                    delete t;
                    t = tmp;
                }
                else
                {   
                    Stack<Node<T>*> s;//用以记录tmp->left沿线的右节点，方便后续旋转
                    s.Push(tmp);
                    //右子树的最小左叶子节点代替t的位置 
                    while(nullptr != tmp->left->left)
                    {
                        tmp = tmp->left;
                        s.Push(tmp);
                    }
                    Node<T>* rtn = tmp->left;
                    tmp->left = rtn->right;
                    tmp = s.Pop();
                    while(nullptr != tmp)
                    {
                        _SetHeight(tmp);
                        tmp = s.Pop();
                    }
                    rtn->left = t->left;
                    rtn->right = t->right;
                    
                    delete t;
                    t = rtn;
                }
            }
            
            size--;
        }
        _SetHeight(t);

        return t;

    }
private:

	Node<T>* head;
	uint32_t size;
};

void avlTreeTest();
#endif /* !AVLTREE_H */
