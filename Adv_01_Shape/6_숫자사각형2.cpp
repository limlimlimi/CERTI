/*
6_���ڻ簢��2
240630 SUN
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
using namespace std;
//���� - �ڵ� ���� ������ - �������� - .snippet

#define MAX_NUM 100

void ps(int n, int m) { //problem solving ���� ��Ģ��� ä���, �����
	int arr[MAX_NUM][MAX_NUM];

	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cnt++;
			if (i % 2 == 0)
				arr[i][j] = cnt;
			else
				arr[i][m - 1 - j] = cnt;
			//cout << cnt<<" ";
		}
		//cout << endl;
	}
	//cout << endl;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}

int main() {
#ifndef ONLINE_JUDGE //IF NOT Define : ONLINE_JUDGE ���� �����ϴ°� �ƴϸ� freopen �����
	freopen("input_5.txt", "r", stdin);
#endif

#ifdef _WIN32 //window���� �����°Ÿ� ������ �����, linux �����̸� �ȿ���.
	freopen("input_5.txt", "r", stdin);
#endif

	int n, m; //����n , �ʺ�m //��n, ��m
	cin >> n;
	cin >> m;

	ps(n, m);

	return 0;
}
