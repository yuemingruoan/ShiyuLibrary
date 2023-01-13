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
	_sm = SortMethod::TimSort;
}

SArray::SArray(double* arr, int size)
{
	_data.resize(size);
	for (int i = 0; i < size; i++)
	{
		_data[i] = arr[i];
	}
	_sm = SortMethod::TimSort;
}

SArray::SArray(const vector<double>& v)
{
	_data = v;
	_sm = SortMethod::TimSort;
}

SArray::SArray(initializer_list<double> l)
{
	for (double n : l)
	{
		_data.push_back(n);
	}
	_sm = SortMethod::TimSort;
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

void SArray::init(initializer_list<double> l)
{
	_data.clear();
	for (double d : l)
	{
		_data.push_back(d);
	}
}

void SArray::setSortMethod(SortMethod sm)
{
	_sm = sm;
}

void SArray::addFront(double d)
{
	_data.emplace(_data.begin(), d);
}

void SArray::addBack(double d)
{
	_data.emplace_back(d);
}

double SArray::getFront()
{
	return _data.front();
}

double SArray::getBack()
{
	return _data.back();
}

void SArray::delFront()
{
	_data.erase(_data.begin());
}

void SArray::delBack()
{
	_data.pop_back();
}

void SArray::del(int i)
{
	_data.erase(_data.begin() + i);
}

void SArray::del(int a, int b)
{
	_data.erase(_data.begin() + a, _data.begin() + b);
}

size_t SArray::size()
{
	return _data.size();
}

void SArray::print(string end)
{
	const int MAX_LINE = 10;

	short n_line = 0;
	for (double d : _data)
	{
		cout << d << "\t";
		n_line = (n_line + 1) % 10;
		if (n_line == 0) cout << '\n';
	}
	cout << end;
}

/*--------------------------------------------
函数用处： 冒泡排序;
创建者： X;
作者邮箱： 2817548451@qq.com;
编写时间： 2023.1.14;
是否完整：是;
当前存在BUG: 无;
注意事项： 喵;
-------------------------------------------*/
void BubbleSort(vector<double>& v, bool desc = 0)
{
	if (v.size() < 1) 
	{
		return;
	}
	for (int i = v.size() - 1; i > 0; i--)
	{
		for (int j = 0; j < i; j++)
		{
			if (desc == false)
			{
				if (v[j] > v[j + 1])
				{
					swap(v[j], v[j + 1]);
				}
			}
			else
			{
				if (v[j] < v[j + 1])
				{
					swap(v[j], v[j + 1]);
				}
			}
		}
	}
}

/*--------------------------------------------
函数用处： 选择排序;
创建者： X;
作者邮箱： 2817548451@qq.com;
编写时间： 2023.1.14;
是否完整：是;
当前存在BUG: 无;
注意事项： 喵;
-------------------------------------------*/
void SelectionSort(vector<double>& v, bool desc = 0)
{
	if (v.size() < 1)
	{
		return;
	}
	for (int i = 0; i < v.size() - 1; i++)
	{	
		if (desc == false)
		{
			int p_min = i;
			for (int j = i + 1; j < v.size(); j++)
			{
				if (v[p_min] > v[j])
				{
					p_min = j;
				}
			}
			swap(v[i], v[p_min]);
		}
		else
		{
			int p_max = i;
			for (int j = i + 1; j < v.size(); j++)
			{
				if (v[p_max] < v[j])
				{
					p_max = j;
				}
			}
			swap(v[i], v[p_max]);
		}
	}
}

/*--------------------------------------------
函数用处： 插入排序;
创建者： X;
作者邮箱： 2817548451@qq.com;
编写时间： 2023.1.14;
是否完整：是;
当前存在BUG: 无;
注意事项： 喵;
-------------------------------------------*/
void __insertion_sort(vector<double>& v, int a, int b, bool desc)
{
	if (b - a < 1)
	{
		return;
	}
	for (int i = a; i <= b; i++)
	{
		for (int j = i; j > a; j--)
		{
			if (desc == false)
			{
				if (v[j] < v[j - 1])
				{
					swap(v[j], v[j - 1]);
				}
				else
				{
					break;
				}
			}
			else
			{
				if (v[j] > v[j - 1])
				{
					swap(v[j], v[j - 1]);
				}
				else
				{
					break;
				}
			}
		}
	}
}
void InsertionSort(vector<double>& v, bool desc = 0)
{
	__insertion_sort(v, 0, v.size() - 1, desc);
}

/*--------------------------------------------
函数用处： 希尔排序;
创建者： X;
作者邮箱： 2817548451@qq.com;
编写时间： 2023.1.14;
是否完整：是;
当前存在BUG: 无;
注意事项： 喵;
-------------------------------------------*/
void ShellSort(vector<double>& v, bool desc = 0)
{
	if (v.size() < 1)
	{
		return;
	}
	int gap = (v.size() >> 1) - 1;
	while (gap > 0)
	{
		for (int i = 0; i < gap; i++)
		{
			for (int j = i; j < v.size(); j += gap)
			{
				if (desc == false)
				{
					int p_min = j;
					for (int k = j + gap; k < v.size(); k += gap)
					{
						if (v[k] < v[p_min])
						{
							p_min = k;
						}
					}
					swap(v[j], v[p_min]);
				}
				else
				{
					int p_max = j;
					for (int k = j + gap; k < v.size(); k += gap)
					{
						if (v[k] > v[p_max])
						{
							p_max = k;
						}
					}
					swap(v[j], v[p_max]);
				}
			}
		}
		gap = (gap >> 1) - 1;
	}
}

/*--------------------------------------------
函数用处： 归并排序;
创建者： X;
作者邮箱： 2817548451@qq.com;
编写时间： 2023.1.14;
是否完整：是;
当前存在BUG: 无;
注意事项： 喵;
-------------------------------------------*/
void __merge(vector<double>& v, int a, int m, int b, bool desc)
{
	int p = a, q = m + 1, k = 0;
	double* tmparr = new double[b - a + 1];
	while (p <= m && q <= b)
	{
		if (desc == false)
		{
			if (v[p] < v[q])
			{
				tmparr[k++] = v[p++];
			}
			else
			{
				tmparr[k++] = v[q++];
			}
		}
		else
		{
			if (v[p] > v[q])
			{
				tmparr[k++] = v[p++];
			}
			else
			{
				tmparr[k++] = v[q++];
			}
		}
	}
	while (p <= m)
	{
		tmparr[k++] = v[p++];
	}
	while (q <= b)
	{
		tmparr[k++] = v[q++];
	}
	for (int i = a; i <= b; i++)
	{
		v[i] = tmparr[i - a];
	}
	delete[] tmparr;
}
void __merge_sort(vector<double>& v, int a, int b, bool desc)
{
	if (b - a < 1)
	{
		return;
	}
	int m = a + ((b - a) >> 1);
	__merge_sort(v, a, m, desc);
	__merge_sort(v, m + 1, b, desc);

	__merge(v, a, m, b, desc);
}
void MergeSort(vector<double>& v, bool desc = 0)
{
	__merge_sort(v, 0, v.size() - 1, desc);
}

/*--------------------------------------------
函数用处： 快速排序;
创建者： X;
作者邮箱： 2817548451@qq.com;
编写时间： 2023.1.14;
是否完整：是;
当前存在BUG: 元素个数太多时倒序排序就会莫名其妙出问题;
注意事项： 喵;
-------------------------------------------*/
void __quick_sort(vector<double>& v, int a, int b, bool desc)
{
	if (b - a < 1) return;
	int l = a, r = b;
	while (l != r)
	{
		while (l != r)
		{
			if (desc == false)
			{
				if (v[r] >= v[l])
				{
					r--;
				}
				else
				{
					swap(v[l], v[r]);
					break;
				}
			}
			else
			{
				if (v[r] <= v[l])
				{
					r--;
				}
				else
				{
					swap(v[l], v[r]);
					break;
				}
			}
		}
		while (l != r)
		{
			if (desc == false)
			{
				if (v[l] <= v[r])
				{
					l++;
				}
				else
				{
					swap(v[l], v[r]);
					break;
				}
			}
			else
			{
				if (v[l] >= v[r])
				{
					l++;
				}
				else
				{
					swap(v[l], v[r]);
					break;
				}
			}
		}
	}
	__quick_sort(v, a, l - 1, desc);
	__quick_sort(v, r + 1, b, desc);
}
void QuickSort(vector<double>& v, bool desc = 0)
{
	__quick_sort(v, 0, v.size() - 1, desc);
}

/*--------------------------------------------
函数用处： Tim 排序;
创建者： X;
作者邮箱： 2817548451@qq.com;
编写时间： 2023.1.14;
是否完整：是;
当前存在BUG: 无;
注意事项： 喵;
-------------------------------------------*/
void TimSort(vector<double>& v, bool desc = 0)
{
	if (v.size() < 1)
	{
		return;
	}
	
	const int MIN_MERGE = 64;

	//求minRun的值
	int n = v.size(), r = 0;
	while (n >= MIN_MERGE)
	{
		r |= (n & 1);
		n >>= 1;
	}
	int minRun = n + r;

	//排序子数组
	for (int start = 0; start < v.size(); start += minRun)
	{
		int end = min(start + minRun - 1, v.size() - 1);
		__insertion_sort(v, start, end, desc);
	}

	//开始归并有序子数组
	int size = minRun;
	while (size < v.size())
	{
		for (int left = 0; left < v.size(); left += 2 * size)
		{
			int mid = min(v.size() - 1, left + size - 1);
			int right = min(left + 2 * size - 1, v.size() - 1);
			if (mid < right)
			{
				__merge(v, left, mid, right, desc);
			}
		}
		size <<= 1;
	}
}

void SArray::sortAscend()
{
#define SM(method) case SortMethod::method: method(_data);break
	switch (_sm)
	{
		SM(BubbleSort);
		SM(SelectionSort);
		SM(InsertionSort);
		SM(ShellSort);
		SM(MergeSort);
		SM(QuickSort);
		SM(TimSort);
	}
#undef SM
}

void SArray::sortDescend()
{
#define SM(method) case SortMethod::method: method(_data, true);break
	switch (_sm)
	{
		SM(BubbleSort);
		SM(SelectionSort);
		SM(InsertionSort);
		SM(ShellSort);
		SM(MergeSort);
		SM(QuickSort);
		SM(TimSort);
	}
#undef SM
}

double& SArray::operator[](int index)
{
	{
		//TODO: 尚未支持负索引
		if (index < 0 || index >= _data.size())
		{
			throw "访问数组越界了喵";
			//TODO:造个异常系统吧
		}
		else
		{
			return _data[index];
		}
	}
}
