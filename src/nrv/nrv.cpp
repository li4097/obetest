/*
 * nrv.cpp
 * Copyright (C) 2019/04/09 LQ 
 *
 * Distributed under terms of the MIT license.
 */

#include "nrv.h"


NrvTest foo(double v)
{
	cout << "============================\n";
	cout << "foo start " << v << endl;
	NrvTest t;
	t.array[0] = v;
	t.array[99] = v;
	t.a = v;
#ifdef USE_NRV
	cout << "foo end " << v << endl;
#endif
	cout << "============================\n";

	return t;
}

int MyTest(NrvTest & tt)
{
	cout << "MyTest1:"<< tt.array[0] << endl;
	return 1;
}
NrvTest::NrvTest(int a)
		:b(a),
		a(b)
{
	array = new double[100];
	memset(array,-1,100 * sizeof(double));
}
