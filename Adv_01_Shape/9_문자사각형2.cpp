/*
9_���ڻ簢��2
240630 SUN
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
using namespace std;
//���� - �ڵ� ���� ������ - �������� - .snippet

#define MAX_NUM 100
char arr[MAX_NUM][MAX_NUM];

void ps(int n) {

	char c = 'A';
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if(i%2 == 0)
				arr[j][i] = c;
			else
				arr[n-1-j][i] = c;
			//cout << c << " ";
			c++;
			if (c == 'Z' + 1)
				c = 'A';
		}
		//cout << endl;
	}
	//cout << endl;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
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
	
	ps(n);
	
	return 0;
}
