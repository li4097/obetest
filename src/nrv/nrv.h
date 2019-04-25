/*
 * nrv.h
 * Copyright (C) 2019 LQ <LQ@localhost.localdomain>
 *
 * Distributed under terms of the MIT license.
 */

#ifndef NRV_H
#define NRV_H

#include <iostream>
#include <memory.h>

using namespace std;
class NrvTest
{
public:
	NrvTest()
	{
		a = 0;
		b = 0;
		cout << "-------------------------\n";
		cout << "call default constructor" << endl;
		array = new double[100];
		memset(array,-1,100 * sizeof(double));
		cout << "-------------------------\n";
	}
	NrvTest(int a);
	~NrvTest(){
		cout << "-------------------------\n";
		cout << "~NrvTest "<< a << " start"<< endl;
		if(array != NULL)
		{
			cout << "p: "<<array << endl;
			delete []array;
		}
		cout << "~NrvTest "<< a << endl;
		cout << "-------------------------\n";
	};


#ifdef USE_NRV
	inline NrvTest(const NrvTest& n)
	{
		cout << "call copy constructor" << endl;
		array = new double[100];
		memcpy(this->array,n.array,sizeof(double) * 100);
	}
#endif
    NrvTest(NrvTest&& n)
	{
		cout << "call move constructor" << endl;
		array = n.array;
		n.array = NULL;
	}

	NrvTest& operator=(const NrvTest& n)
	{
		if(array == nullptr)
		{
			array = new double[100];
		}
		memcpy(array,n.array,sizeof(double)* 100);
		a = n.a;

		return *this;
	}
	int a;
	int b;
	double* array;
};

int MyTest(NrvTest & tt);
NrvTest foo(double v);


#endif /* !NRV_H */
