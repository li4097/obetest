/*
 * binarytree.h
 * Copyright (C) 2019 LQ <LQ@localhost.localdomain>
 *
 * Distributed under terms of the MIT license.
 */

#ifndef BINARYTREE_H
#define BINARYTREE_H

#include "utility.h"

template<class T>
struct Node {
	Node(const T& data,uint8_t height)
		:data(data),
		height(height+1),
		left(nullptr),
		right(nullptr)
	{}
	Node(const T& data)
		:data(data),
		height(0),
		left(nullptr),
		right(nullptr)
	{}
	T data;
	uint8_t height;
	Node* left;
	Node* right;
};

template<class T>
class BinaryTree{
public:
	BinaryTree()
	:head(nullptr),
		size(0)
	{}
	~BinaryTree()
	{};

    uint32_t GetSize()
    {
        return size;
    }
	Node<T>* GetHead()
	{
		return head;
	}
	bool Insert(const T& data)
	{
		Node<T>* n = head;
		if(nullptr == n)
		{
			head = new Node<T>(data);
			size = 1;
			return true;
		}
		while(nullptr != n)
		{
			if(n->data > data)
			{
				if(nullptr == n->left)
				{
					n->left = new Node<T>(data,n->height);
					n = n->left;
					break;
				}
				n = n->left;
			}
			else if(n->data < data)
			{
				if(nullptr == n->right)
				{
					n->right = new Node<T>(data,n->height);
					n = n->right;
					break;
				}
				n = n->right;
			}
			else
			{
				n = nullptr;
			}
		}
		if (nullptr != n)
		{
			size++;
		}

		return true;

	}
	void Delete(const T& data)
	{
		Node<T>* n = head;
		if (nullptr == n)
		{
			return;
		}
		bool isLeft = true;
		Node<T>* prev = nullptr;
		while(nullptr != n)
		{
			if(n->data > data)
			{
				isLeft = true;
				prev = n;
				n = n->left;
			}
			else if (n->data < data)
			{
				isLeft = false;
				prev = n;
				n = n->right;
			}
			else
			{
				//找出右子树中最小节点替代原节点
				Node<T>* tmp = nullptr;
				if(nullptr == n->right)
				{
					tmp = n->left;
				}
				else if(nullptr == n->right->left)
				{
					tmp = n->right;
					tmp->left = n->left;
				}
				else
				{
					tmp = n->right;
					while(nullptr != tmp->left->left)
					{
						tmp = tmp->left;
					}
					tmp = tmp->left;
					tmp->left = n->left;
				}
				if(tmp)
				{
					tmp->height = n->height;
				}
				if(nullptr == prev)
				{
					n = tmp;
					delete head;
					head = n;
				}
				else if(isLeft)
				{
					prev->left = tmp;
					delete n;
				}
				else
				{
					prev->right = tmp;
					delete n;
				}
				return;
			}
		}
	}
	static void TraversalM(Node<T>* n)
	{	
		Stack<Node<T>*> s;
		while(n)
		{
			while(n)
			{
				s.Push(n);
				n = n->left;
			}
			while(!n)
			{
				n = s.Pop();
				if(nullptr == n)
				{
					break;
				}
				Print(n);
				n = n->right;
			}

		}
	}
	static void TraversalL(Node<T>* n)
	{	
		Stack<Node<T>*> s;
		while(n)
		{
			while(n)
			{
				Print(n);
				s.Push(n);
				n = n->left;
			}
			while(!n)
			{
				n = s.Pop();
				if(nullptr == n)
				{
					break;
				}
				n = n->right;
			}

		}
	}
	static void TraversalR(Node<T>* n)
	{
		
		Stack<Node<T>*> s;
		Stack<Node<T>*> sL;
		while(n)
		{
			while(n)
			{
				s.Push(n);
				if(n->left)
				{
					sL.Push(n->left);
				}
				n = n->right;
			}
			n = sL.Pop();
		}

		n = s.Pop();
		while(n)
		{
			Print(n);
			n = s.Pop();
		}
	}
	static void Print(Node<T>* n)
	{
		if(nullptr == n)
		{
			return;
		}
		cout << (int)n->height << " ";
		uint32_t count = 20 - n->height;
		for(uint32_t i = 0; i < count; i++)
		{
			cout << "--";
		}
		cout << "|";
		cout << " " << n->data << endl;
	}
private:


private:

	Node<T>* head;
	uint32_t size;
};

#endif /* !BINARYTREE_H */
