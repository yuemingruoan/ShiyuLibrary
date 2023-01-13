#include<iostream>
#include<string>
#include"ShiyuLibrary.h"
using namespace std;
int main()
{
	//随机生成测试样例
	srand((unsigned)time(0));

	const int n_samples = 10; //测试样例数

	double d[n_samples];
	for (int i = 0; i < n_samples; i++)
	{
		d[i] = rand() % 2000;
	}
	SArray a(d, n_samples);

	//设置排序的方式
	a.setSortMethod(SArray::SortMethod::QuickSort);

	//打印原始数据
	cout << "测试样例" << endl;
	a.print();

	//从小到大排序并打印
	a.sortAscend();
	cout << "从小到大:" << endl;
	a.print();

	//从大到小排序并打印
	a.sortDescend();
	cout << "从大到小" << endl;
	a.print();

	//打印一头一尾的数据
	cout << "开头的元素是: " << a.getFront() << endl;
	cout << "结尾的元素是: " << a.getBack()  << endl << endl;
	
	//对数组的某一项的操作(读和写)
	cout << "a[2] = " << a[2] << endl << endl;
	a[3] = 131.4;
	
	//对数组开头的插入
	a.addFront(520);
	a.print("\n\n");

	//对数组结尾的插入
	a.addBack(114514);
	a.print("\n\n");

	//删除开头和结尾的元素
	a.delFront();
	a.delBack();
	a.print("\n\n");

	//删除中间的元素
	a.del(4);
	a.print("\n\n");

	//删除一大片元素
	a.del(0, 3);
	a.print();
	
	return 0;
}
