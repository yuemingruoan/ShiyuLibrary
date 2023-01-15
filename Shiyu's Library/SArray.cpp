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
	for (; number > 0; number--)
	{
		for (int b = 0; b <= number - 1; b++)
		{
			if (Array[b] < Array[b + 1])
			{

			}
			else swap(Array[b], Array[b + 1]);
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
