/*
7_숫자사각형3
240630 SUN
*/

#define MAX_NUM 100

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
using namespace std;
//도구 - 코드 조각 관리자 - 가져오기 - .snippet

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
#ifndef ONLINE_JUDGE //IF NOT Define : ONLINE_JUDGE 에서 실행하는게 아니면 freopen 열어라
	freopen("input_7.txt", "r", stdin);
#endif

#ifdef _WIN32 //window에서 돌리는거면 파일을 열어라, linux 서버이면 안연다.
	freopen("input_7.txt", "r", stdin);
#endif

	int n;
	cin >> n;

	ps(n);

	return 0;
}
