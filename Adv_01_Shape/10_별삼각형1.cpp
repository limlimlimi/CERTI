/*
���ﰢ��1
240701 MON
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
using namespace std;
//���� - �ڵ� ���� ������ - �������� - .snippet

void ps(int n, int m) {
	if(n>100)
		cout << "INPUT ERROR!";

	else
		switch (m)
		{
		case 1:
			for (int i = 0; i < n; i++) {
				for (int j = 0; j <= i; j++) {
					cout << "*";
				}
				cout << endl;
			}
			break;

		case 2:
			for (int i = 0; i < n; i++) {
				for (int j = i; j < n; j++) {
					cout << "*";
				}
				cout << endl;
			}
			break;

		case 3:
			for (int i = 0; i < n; i++) {

				//���� ��� (ù�� : n-1�� ���, ��°�� : n-2��)
				for (int j = 0; j < n-1-i; j++) {
					cout << " ";
				}

				//�� ���
				for (int j = 0; j < 2*(i+1)-1; j++) {
					cout << "*";
				}
			
				//�ٹٲ�
				cout << endl;
			}
			break;
		
		default:
			cout << "INPUT ERROR!";
		}
}

int main() {
#ifndef ONLINE_JUDGE //IF NOT Define : ONLINE_JUDGE ���� �����ϴ°� �ƴϸ� freopen �����
	freopen("input_10.txt", "r", stdin);
#endif

#ifdef _WIN32 //window���� �����°Ÿ� ������ �����, linux �����̸� �ȿ���.
	freopen("input_10.txt", "r", stdin);
#endif
	
	int n, m;
	cin >> n;
	cin >> m;
	ps(n,m);

	return 0;
}
