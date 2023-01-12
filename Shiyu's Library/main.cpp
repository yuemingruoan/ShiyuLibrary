#include<iostream>
#include<string>
#include"ShiyuLibrary.h"
using namespace std;
int main()
{
	string a = "C:\\Users\\Administrator\\Desktop\\QQ½ØÍ¼20230112173430.png";
	a = Encoding::PhotoToBase64(a);
	cout << a <<endl;

	cout << "Hello World!" << endl;
	return 0;
}