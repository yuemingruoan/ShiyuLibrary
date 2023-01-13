#include<iostream>
#include<string>
#include"ShiyuLibrary.h"
using namespace std;
int main()
{
	//������ɲ�������
	srand((unsigned)time(0));

	const int n_samples = 10; //����������

	double d[n_samples];
	for (int i = 0; i < n_samples; i++)
	{
		d[i] = rand() % 2000;
	}
	SArray a(d, n_samples);

	//��������ķ�ʽ
	a.setSortMethod(SArray::SortMethod::QuickSort);

	//��ӡԭʼ����
	cout << "��������" << endl;
	a.print();

	//��С�������򲢴�ӡ
	a.sortAscend();
	cout << "��С����:" << endl;
	a.print();

	//�Ӵ�С���򲢴�ӡ
	a.sortDescend();
	cout << "�Ӵ�С" << endl;
	a.print();

	//��ӡһͷһβ������
	cout << "��ͷ��Ԫ����: " << a.getFront() << endl;
	cout << "��β��Ԫ����: " << a.getBack()  << endl << endl;
	
	//�������ĳһ��Ĳ���(����д)
	cout << "a[2] = " << a[2] << endl << endl;
	a[3] = 131.4;
	
	//�����鿪ͷ�Ĳ���
	a.addFront(520);
	a.print("\n\n");

	//�������β�Ĳ���
	a.addBack(114514);
	a.print("\n\n");

	//ɾ����ͷ�ͽ�β��Ԫ��
	a.delFront();
	a.delBack();
	a.print("\n\n");

	//ɾ���м��Ԫ��
	a.del(4);
	a.print("\n\n");

	//ɾ��һ��ƬԪ��
	a.del(0, 3);
	a.print();
	
	return 0;
}
