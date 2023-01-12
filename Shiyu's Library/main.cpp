#include<iostream>
#include<string>
#include"ShiyuLibrary.h"
using namespace std;
int main()
{
	string a;
	a = "ÄãºÃÑ½";
	a = Encoding::TextToBase64(a);
	cout << a << endl;
	cout << "Hello World!" << endl;
	return 0;
}