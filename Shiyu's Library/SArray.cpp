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
string SArray::ArrayPrint(int arr[])
{
    string a;
    int sum = sizeof(arr)/sizeof(int);//因为系统不同，位数不同，int不一定为4字节，所以用sizeof
    for (int j = 0; j < sum; j++)
    {
            a += arr[j] + " ";
    }
   return a;
}
string SArray::ArrayPrint(int arr[],int number)
{
    string a;
    for (int j = 0; j < number; j++)
    {
        a += arr[j] + " ";
    }
    return a;
}


