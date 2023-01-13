#include<iostream>
#include<iomanip>
#include<cmath>
#include<algorithm>
#include<string>
#include<windows.h>
#include<fstream>
#include<ios>
#include"assert.h"
#include <codecvt> 
#include <locale> 
#include"ShiyuLibrary.h"
using namespace std;

SArray::SArray()
{
	_sm = SortMethod::BubbleSort;
}

SArray::SArray(double* arr, int size)
{
	_data.resize(size);
	for (int i = 0; i < size; i++)
	{
		_data[i] = arr[i];
	}
	_sm = SortMethod::BubbleSort;
}

SArray::SArray(const vector<double>& v)
{
	_data = v;
	_sm = SortMethod::BubbleSort;
}

SArray::SArray(initializer_list<double> l)
{
	for (double n : l)
	{
		_data.push_back(n);
	}
}

SArray::~SArray()
{
	_data.~vector();
}

void SArray::init(double* arr, int size)
{
	_data.resize(size);
	for (int i = 0; i < size; i++)
	{
		_data[i] = arr[i];
	}
}

void SArray::init(const vector<double>& v)
{
	_data = v;
}

void SArray::print()
{
	for (double d : _data)
	{
		cout << d << ' ';
	}
	cout << endl;
}


void BubbleSort(vector<double>& v, bool desc = 0)
{
	for (int i = v.size() - 1; i > 0; i--)
	{
		for (int j = 0; j < i; j++)
		{
			if (desc == false)
			{
				if (v[j] > v[j + 1])
				{
					int tmp = v[j];
					v[j] = v[j + 1];
					v[j + 1] = tmp;
				}
			}
			else
			{
				if (v[j] < v[j + 1])
				{
					int tmp = v[j];
					v[j] = v[j + 1];
					v[j + 1] = tmp;
				}
			}
		}
	}
}


void SArray::sort_asc()
{
#define LABEL(method) case SortMethod::method: method(_data);break
	switch (_sm)
	{
		LABEL(BubbleSort);

	}
#undef LABEL
}

void SArray::sort_desc()
{
#define LABEL(method) case SortMethod::method: method(_data, 1);break
	switch (_sm)
	{
		LABEL(BubbleSort);

	}
#undef LABEL
}
