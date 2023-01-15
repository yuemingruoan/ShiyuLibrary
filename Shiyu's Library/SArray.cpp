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
string SArray::ArrayToString(int arr[],int number)
{
    string a;
    for (int j = 0; j < number-1; j++)
    {
        a += to_string(arr[j])  + ",";
    }
    a += to_string(arr[number - 1]);
    return a;
}
void SArray::BubbleSort(int Array[], int number)
{
	for (int i = 0; i < number - 1; i++)
	{
		for (int j = 0; j < number - i - 1; j++)
		{
			if (Array[j] > Array[j + 1])
			{
				int temp = Array[j];
				Array[j] = Array[j + 1];
				Array[j + 1] = temp;
			}
		}
	}
}
int SArray::ArrayGetMax(int Array[],int number)
{
	int max = 0;
	for (int i = 0; i <= number; i++)
	{
		if (Array[i] > max)
		{
			max = Array[i];
		}
		else
		{

		}
	}
	return max;
}
void SArray::ArrayUpsetDown(int Array[], int number)
{
	int end = number - 1;
	int begin = 0;
	for (; end <= begin; end--, begin++)
	{
		int a = 0;
		Array[begin] = a;
		Array[begin] = Array[end];
		Array[end] = Array[begin];
		
	}
}