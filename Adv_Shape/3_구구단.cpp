/*
������
240630 SUN
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <iomanip>
using namespace std;
//���� - �ڵ� ���� ������ - �������� - .snippet

int main() {
#ifndef ONLINE_JUDGE //IF NOT Define : ONLINE_JUDGE ���� �����ϴ°� �ƴϸ� freopen �����
	freopen("input_3.txt", "r", stdin);
#endif

//#ifdef _WIN32 //window���� �����°Ÿ� ������ �����, linux �����̸� �ȿ���.
//	freopen("input_3.txt", "r", stdin);
//#endif

	int s, e;
	//cout << "s : " << s << " & e = " << e << endl;

	// s,e is out of range
	while (1) {
		cin >> s;
		cin >> e;
		if (s < 2 or s>9 or e < 2 or e>9)
			cout << "INPUT ERROR!\n";
		else
			break;
	}

	int a;
	if(s > e)
		a = -1;	//s > e
	else 
		a = 1;	//s <= e

	//cout << "a = " << a << endl;

	//int cnt = 0;
	for (int j = 1; j < 10; j++) {
		//cnt++;
		//cout << cnt << " : ";
		for (int i = s; i != e+a; i+=a) {
			cout << i << " * " << j << " = " << setw(2) << i*j; //formating ���� �ڸ���
			if (i != e)
				cout << "   ";
		}
		cout << endl;
	}
	
	//float pi = 3.141592;
	//cout << "float pi :        " << pi << endl;
	//cout << "setw(10) :         " << setw(10) << pi << endl;
	////setw ���� ���� (pi)�� �Ҽ��� ���� ��� ���� ���� + ��ĭ == 10
	//cout << "setprecision(5) : " << setprecision(5) << pi << endl; 
	////�Ҽ��� ���� �ڸ��� = �Ҽ��� ���� �ڸ��� +  �Ҽ��� ���� ��� ��ȿ������ �ڸ���

	return 0;
}
