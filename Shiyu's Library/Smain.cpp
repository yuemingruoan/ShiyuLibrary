#include<iostream>
#include<string>
#include"ShiyuLibrary.h"
using namespace std;
int main()
{
	int a[2] = { 1,2 };
	string b = SArray::ArrayPrint(a,2);
	cout << b << endl;
	return 0;
}
