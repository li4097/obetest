/*
 * avltree.cpp
 * Copyright (C) 2019/04/25 LQ 
 *
 * Distributed under terms of the MIT license.
 */

#include "avltree.h"


void avlTreeTest()
{
    srand((unsigned int)time(NULL));
    AVLTree<int> a;
    BinaryTree<int> b;
    for(int i = 0; i < 180; i++)
    {
        int num = rand() % 500;
        a.Insert(num);
        b.Insert(num);

        //system("clear");
        //cout << "\n--------------Avl----------- " << a.GetSize() << " ----"<<endl;
        //BinaryTree<int>::TraversalL(a.GetHead());
        //getchar();
    }

    cout << "\n--------------Avl----------- " << a.GetSize() << " ----"<<endl;
    BinaryTree<int>::TraversalM(a.GetHead());
    cout << "\n--------------BST----------- " << b.GetSize() << " ----"<<endl;
    BinaryTree<int>::TraversalM(b.GetHead());

}
