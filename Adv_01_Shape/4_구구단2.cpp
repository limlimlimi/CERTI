/*
������2
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
	freopen("input_4.txt", "r", stdin);
#endif

#ifdef _WIN32 //window���� �����°Ÿ� ������ �����, linux �����̸� �ȿ���.
	freopen("input_4.txt", "r", stdin);
#endif

	int s, e;
	cin >> s;
	cin >> e;
	
	int a;
	if (s > e)
		a = -1;
	else
		a = 1;

	//cout << s << " , " << e << " , " << a << endl;

	for (int j = s; j != e + a; j += a) {
		for (int i = 1; i < 10; i++) {
			cout << j << " * " << i << " = " << setw(2) << i * j ;
			if (i % 3 == 0)
				cout << endl;
			else
				cout << "   ";
		}
		cout << endl;
	}
	return 0;
}
