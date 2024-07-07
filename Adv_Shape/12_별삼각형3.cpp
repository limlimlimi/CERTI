/*
별삼각형3
240701 MON
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
using namespace std;
//도구 - 코드 조각 관리자 - 가져오기 - .snippet

void ps(int n) {
	if (n > 100 or n % 2 == 0)
		cout << "INPUT ERROR!";
	else {
		//top shape
		for (int i = 0; i < n/2+1; i++){
			//star
			for (int j = 0; j < i; j++) {
				cout << " ";
			}

			//star
			for (int j = 0; j < 2*i+1; j++) { //문자 변수개 출력하는 방법 이거구나!!
				cout << "*"; 
			}

			//line feed
			cout << endl;
		}

		//bottom shape
		for (int i = 0; i < n/2; i++) {
			//empty
			for (int j = 0; j < n/2-1-i; j++) {
				cout << " ";
			}

			//star
			for (int j = 0; j < 2*(n/2-i)-1; j++) { //문자 변수개 출력하는 방법 이거구나!!
				cout << "*"; 
			}

			//line feed
			cout << endl;
		}
	}

}

int main() {
#ifndef ONLINE_JUDGE //IF NOT Define : ONLINE_JUDGE 에서 실행하는게 아니면 freopen 열어라
	freopen("input_12.txt", "r", stdin);
#endif

#ifdef _WIN32 //window에서 돌리는거면 파일을 열어라, linux 서버이면 안연다.
	freopen("input_12.txt", "r", stdin);
#endif
	
	int n;
	cin >> n;
	
	ps(n);

	return 0;
}
