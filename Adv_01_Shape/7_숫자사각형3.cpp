/*
7_���ڻ簢��3
240630 SUN
*/

#define MAX_NUM 100

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
using namespace std;
//���� - �ڵ� ���� ������ - �������� - .snippet

int arr[MAX_NUM][MAX_NUM];

void ps(int n) {

	int cnt = 0;
	for (int j = 0; j < n; j++) {
		for (int i = 0; i < n; i++) {
			cnt++;
			arr[i][j] = cnt;
		}
	}

	for (int i = 0; i < n; i++) {
		for(int j=0; j<n; j++) {
			cout<< arr[i][j] << " ";
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
