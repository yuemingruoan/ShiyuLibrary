#include<iostream>
#include<string>
#include"ShiyuLibrary.h"
using namespace std;
int main()
{
	string a;
	a = "���ѽ";
	a = Encoding::TextToBase64(a);
	cout << a << endl;
	cout << "Hello World!" << endl;
	return 0;
}