/*
���ڻ簢��1
240630 SUN
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
using namespace std;
//���� - �ڵ� ���� ������ - �������� - .snippet

#define MAX_NUM 100
char arr[MAX_NUM][MAX_NUM]; //int�� �����ϰ�, char ������ �ƽ�Ű�ڵ忡 �ش��ϴ� ���ڷ� ���

void ps(int n) {

	char c = 'A';
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			arr[n-1-j][n-1-i] = c;
			c++;
			if (c == 'Z'+1)
				c = 'A';
		}
	}

	for (int i = 0; i < n; i++) { //����, ����, ��
		for (int j = 0; j < n; j++) { //����, �ʺ�, ��
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}

int main() {
#ifndef ONLINE_JUDGE //IF NOT Define : ONLINE_JUDGE ���� �����ϴ°� �ƴϸ� freopen �����
	freopen("input_7.txt", "r", stdin);
#endif

#ifdef _WIN32 //window���� �����°Ÿ� ������ �����, linux �����̸� �ȿ���.
	freopen("input_7.txt", "r", stdin);
#endif

	int n;
	cin >> n;

	//// ASCII (�ƽ�Ű�ڵ�)�� ����ȯ(Casting)
	//char c = 'Z';
	//cout << c << endl; //Z
	//cout << int(c); //90
	//cout << int('Z'); //90
	//cout << int('Z' + 1); //91

	ps(n);

	return 0;
}
