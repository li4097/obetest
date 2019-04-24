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
	Node(const T& data,uint8_t level)
		:data(data),
		level(level+1),
		left(nullptr),
		right(nullptr)
	{}
	Node(const T& data)
		:data(data),
		level(0),
		left(nullptr),
		right(nullptr)
	{}
	T data;
	uint8_t level;
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
					n->left = new Node<T>(data,n->level);
					n = n->left;
					break;
				}
				n = n->left;
			}
			else
			{
				if(nullptr == n->right)
				{
					n->right = new Node<T>(data,n->level);
					n = n->right;
					break;
				}
				n = n->right;
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
				if(nullptr != tmp)
				{
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
	}
	void TraversalM()
	{
		cout << "\n--------- M ----------\n";
		_TraversalM(head);
		cout << "\n----------------------\n";
	}
	void TraversalL()
	{
		
		cout << "\n--------- L ----------\n";
		_TraversalL(head);
		cout << "\n----------------------\n";
	}
private:

	void _Print(Node<T>* n)
	{
		if(nullptr == n)
		{
			return;
		}
		for(int i = 0; i < n->level; i++)
		{
			cout << "--";
		}
		cout << "|";
		cout << " " << n->data << endl;
	}
	void _TraversalL(Node<T>* n)
	{	
		Stack<Node<T>*> s;
		while(n)
		{
			while(n)
			{
				_Print(n);
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
	void _TraversalM(Node<T>* n)
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
				_Print(n);
				n = n->right;
			}

		}
	}
private:

	Node<T>* head;
	uint32_t size;
};

#endif /* !BINARYTREE_H */
