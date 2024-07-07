/*
구구단
240630 SUN
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <iomanip>
using namespace std;
//도구 - 코드 조각 관리자 - 가져오기 - .snippet

int main() {
#ifndef ONLINE_JUDGE //IF NOT Define : ONLINE_JUDGE 에서 실행하는게 아니면 freopen 열어라
	freopen("input_3.txt", "r", stdin);
#endif

//#ifdef _WIN32 //window에서 돌리는거면 파일을 열어라, linux 서버이면 안연다.
//	freopen("input_3.txt", "r", stdin);
//#endif

	int s, e;
	//cout << "s : " << s << " & e = " << e << endl;

	// s,e is out of range
	while (1) {
		cin >> s;
		cin >> e;
		if (s < 2 or s>9 or e < 2 or e>9)
			cout << "INPUT ERROR!\n";
		else
			break;
	}

	int a;
	if(s > e)
		a = -1;	//s > e
	else 
		a = 1;	//s <= e

	//cout << "a = " << a << endl;

	//int cnt = 0;
	for (int j = 1; j < 10; j++) {
		//cnt++;
		//cout << cnt << " : ";
		for (int i = s; i != e+a; i+=a) {
			cout << i << " * " << j << " = " << setw(2) << i*j; //formating 숫자 자리수
			if (i != e)
				cout << "   ";
		}
		cout << endl;
	}
	
	//float pi = 3.141592;
	//cout << "float pi :        " << pi << endl;
	//cout << "setw(10) :         " << setw(10) << pi << endl;
	////setw 다음 변수 (pi)의 소수점 제외 모든 숫자 길이 + 빈칸 == 10
	//cout << "setprecision(5) : " << setprecision(5) << pi << endl; 
	////소수점 수의 자리수 = 소수점 이하 자리수 +  소수점 위의 모든 유효숫자의 자리수

	return 0;
}
