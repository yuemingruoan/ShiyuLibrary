#include<iostream>
#include<string>
#include"shiyu.h"
using namespace std;
int main()
{
	string a = "C:\\Users\\Administrator\\Desktop\\QQ��ͼ20230112173430.png";
	a = Encoding::PhotoToBase64(a);
	cout << a <<endl;
	return 0;
}