#include<iostream>
#include<string>
#include"ShiyuLibrary.h"
using namespace std;
int main()
{
	int a[5] = {1,2,1,5,3 };
	SArray::BubbleSort(a, 5);
	cout << SArray::ArrayToString(a, 5) << endl;
	SArray::ArrayUpsetDown(a, 5);
	cout << SArray::ArrayToString(a, 5) << endl;
	return 0;
	system("pause");
}
