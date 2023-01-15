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
string SArray::ArrayPrint(int arr[],int number)
{
    string a;
    for (int j = 0; j < number-1; j++)
    {
        a += to_string(arr[j])  + ",";
    }
    a += to_string(arr[number - 1]);
    return a;
}


