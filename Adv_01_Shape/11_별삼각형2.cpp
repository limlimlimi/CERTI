/*
별삼각형2
240701 MON
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
using namespace std;
//도구 - 코드 조각 관리자 - 가져오기 - .snippet

void case1_function(int n) {
	//윗삼각형 & 중앙
	for (int i = 0; i < (n + 1) / 2; i++) {
		for (int j = 0; j < i + 1; j++) {
			cout << "*";
		}
		cout << endl;
	}
	//아랫삼각형 without center
	for (int i = 0; i < n / 2; i++) {
		for (int j = 0; j < n / 2 - i; j++) {
			cout << "*";
		}
		cout << endl;
	}
}

void case2_function(int n) {
	//윗삼각형 & 중앙
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

	//아랫삼각형 without center
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
	//윗삼각형
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

	//아랫삼각형
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
	//윗삼각형
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

	//아랫삼각형
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
