/*
문자사각형1
240630 SUN
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
using namespace std;
//도구 - 코드 조각 관리자 - 가져오기 - .snippet

#define MAX_NUM 100
char arr[MAX_NUM][MAX_NUM]; //int로 선언하고, char 담으면 아스키코드에 해당하는 숫자로 담김

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

	for (int i = 0; i < n; i++) { //세로, 높이, 열
		for (int j = 0; j < n; j++) { //가로, 너비, 행
			cout << arr[i][j] << " ";
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

	//// ASCII (아스키코드)와 형변환(Casting)
	//char c = 'Z';
	//cout << c << endl; //Z
	//cout << int(c); //90
	//cout << int('Z'); //90
	//cout << int('Z' + 1); //91

	ps(n);

	return 0;
}
