#include<iostream>   // ���������� ����\�����
#include <cstdlib>    //������
#include <ctime>
using namespace std;

int  main()
{
	setlocale(LC_ALL, "Russian"); 
	const int a=10;
	int array[a];
	int *array2=NULL;
	int nechet=0;
	int MIN = 1000, MAX = 0;
	float SRED=0, SUMM = 0;
	srand(time(NULL));  //������������� ������� rand  srand(�����)
	int k=0,p=0; //��������
	cout << "�������� ������" << endl;
	for (int i = 0; i < a; i++)
	{
		array[i] = (rand()%100);
	}
	for (int i = 0; i < a; i++)
	{
		cout <<' '<< array[i];
	}
	cout << endl;

	while (k <a)   //����������
	{
		p = 1;
		while (p < a)
		{
			if (array[p-1] > array[p])
			{
				swap( array[p-1] , array[p]);
			}
			p++;
		}
		k++;

	}
	cout << "�������� ������" << endl;
	for (int i = 0; i < a; i++)
	{
		cout << ' ' << array[i];
	} 
	cout << endl;
	for (int i = 0; i < a; i++)
	{
		if (array[i] % 2 == 1)
		{
			nechet++;
		}
	}
	array2 = new int[nechet];
	k = 0;  //�������
	for (int i = 0; i < a; i++)
	{
		if (array[i] % 2 == 1)
		{
			array2[k] = array[i];
			k++;
		}
	}
	cout << "������ ������� ���������" << endl;
	for (int i = 0; i < nechet; i++)
	{
		cout << ' ' << array2[i];
	}
	cout << endl;
	for (int i = 0; i < nechet; i++) //��������
	{
		if (array2[i] > MAX)
		{
			MAX = array2[i];
		}
	}
	cout <<"�������� = "<< MAX<<endl;
	for (int i = 0; i < nechet; i++) //�������
	{
		if (array2[i] < MIN)
		{
			MIN = array2[i];
		}
	}
	cout <<"������� = "<< MIN<<endl;
	for (int i = 0; i < nechet; i++) //�������
	{
		SUMM = SUMM + array2[i];
	}
	SRED = SUMM / nechet;
	cout <<"������� = " <<SRED<<endl;
	system("pause");
	return 0;
}