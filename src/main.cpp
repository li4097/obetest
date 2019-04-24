/*
 * main.cpp
 * Copyright (C) 2019/04/09 LQ 
 *
 * Distributed under terms of the MIT license.
 */

#include <list>
#include <map>
#include <vector>
#include <functional>
#include "utility.h"
#include "nrv.h"
#include "binarytree.h"


int main()
{
	BinaryTree<int> t;
	t.Insert(4);
	t.Insert(2);
	t.Insert(1);
	t.Insert(3);
	t.Insert(8);
	t.Insert(6);
	t.Insert(7);
	t.Insert(5);
	t.Insert(9);

	t.TraversalL();
	t.TraversalM();

	return 0;
}



