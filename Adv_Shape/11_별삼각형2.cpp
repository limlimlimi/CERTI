/*
���ﰢ��2
240701 MON
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
using namespace std;
//���� - �ڵ� ���� ������ - �������� - .snippet

void case1_function(int n) {
	//���ﰢ�� & �߾�
	for (int i = 0; i < (n + 1) / 2; i++) {
		for (int j = 0; j < i + 1; j++) {
			cout << "*";
		}
		cout << endl;
	}
	//�Ʒ��ﰢ�� without center
	for (int i = 0; i < n / 2; i++) {
		for (int j = 0; j < n / 2 - i; j++) {
			cout << "*";
		}
		cout << endl;
	}
}

void case2_function(int n) {
	//���ﰢ�� & �߾�
	for (int i = 0; i < (n + 1) / 2; i++) {
		//empty
		for (int j = 0; j < n / 2 - i; j++) {
			cout << " ";
		}

		//star
		for (int j = 0; j < i + 1; j++) {
			cout << "*";
		}

		//line feed
		cout << endl;
	}

	//�Ʒ��ﰢ�� without center
	for (int i = 0; i < n / 2; i++) {
		//empty
		for (int j = 0; j < i + 1; j++) {
			cout << " ";
		}

		//star
		for (int j = 0; j < n / 2 - i; j++) {
			cout << "*";
		}

		//line feed
		cout << endl;
	}
}

void case3_function(int n) {
	//���ﰢ��
	for (int i = 0; i < (n+1)/2; i++) {
		//empty
		for (int j = 0; j < i; j++) {
			cout << " ";
		}

		//star
		for (int j = 0; j < n-2*i; j++) {
			cout << "*";
		}
		cout << endl;
	}

	//�Ʒ��ﰢ��
	for (int i = 0; i < n/2; i++) {
		//empty
		for (int j = 0; j < n/2-1-i; j++) {
			cout << " ";
		}

		//star
		for (int j = 0; j < 2*(i+1)+1; j++) {
			cout << "*";
		}
		cout << endl;
	}
}

void case4_function(int n) {
	//���ﰢ��
	for (int i = 0; i < (n + 1) / 2; i++) {
		//empty
		for (int j = 0; j < i; j++) {
			cout << " ";
		}

		//star
		for (int j = 0; j < n/2+1-i; j++) {
			cout << "*";
		}
		cout << endl;
	}

	//�Ʒ��ﰢ��
	for (int i = 0; i < n / 2; i++) {
		//empty
		for (int j = 0; j < n / 2; j++) {
			cout << " ";
		}

		//star
		for (int j = 0; j < 2+i ; j++) {
			cout << "*";
		}
		cout << endl;
	}
}

void ps(int n, int m) {
	if (n > 100 or n % 2 == 0)
		cout << "INPUT ERROR!";
	else{
		switch (m)
		{
		case 1:
			case1_function(n);
			break;

		case 2:
			case2_function(n);
			break;

		case 3:
			case3_function(n);
			break;

		case 4:
			case4_function(n);
			break;

		default:
			cout << "INPUT ERROR!";
			break;
		}
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
