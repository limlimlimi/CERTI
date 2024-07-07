/*
별삼각형1
240701 MON
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
using namespace std;
//도구 - 코드 조각 관리자 - 가져오기 - .snippet

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

				//공백 출력 (첫줄 : n-1개 출력, 둘째줄 : n-2개)
				for (int j = 0; j < n-1-i; j++) {
					cout << " ";
				}

				//별 출력
				for (int j = 0; j < 2*(i+1)-1; j++) {
					cout << "*";
				}
			
				//줄바꿈
				cout << endl;
			}
			break;
		
		default:
			cout << "INPUT ERROR!";
		}
}

int main() {
#ifndef ONLINE_JUDGE //IF NOT Define : ONLINE_JUDGE 에서 실행하는게 아니면 freopen 열어라
	freopen("input_10.txt", "r", stdin);
#endif

#ifdef _WIN32 //window에서 돌리는거면 파일을 열어라, linux 서버이면 안연다.
	freopen("input_10.txt", "r", stdin);
#endif
	
	int n, m;
	cin >> n;
	cin >> m;
	ps(n,m);

	return 0;
}
