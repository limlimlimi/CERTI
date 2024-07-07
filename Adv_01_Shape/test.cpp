/*
문제이름
*/

/*
* VS 사용법
* 연주
* Ctrl + F5 : 코드 실행
* Ctrl + Shift + A : 파일생성
* 프로젝트우클릭+ A : 프로젝트활성화
* 파일우클릭+ R : 파일속성 //main 함수 여러개일 경우, .cpp - 속성 - 빌드에서 제외 : 예
* Ctrl + Shift + // : 개별 주석 처리
* Ctrl + K, C : 해석(comment)
* Ctrl + K, U : 해석해제(comment out)
* Ctrl + D : 줄복사
* Ctrl + L : 줄삭제
* Ctrl + 좌우, Del, 백스페이스 : 단위이동,삭제
*
*디버깅 DEBUGGING
* Ctrl + F10 : 더블위치에서 디버깅 시작 // debug - 창 - 조사식 눌러서 창 열기 가능
* 런던위치로이동
* F10: 한줄실행(함수지나침)
* F11: 한줄실행(함수들어감)
* Shift + F5 : 헤드셋종료 (디버깅 종료)
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
using namespace std;

int main() {
#ifndef ONLINE_JUDGE //IF NOT Define : ONLINE_JUDGE 에서 실행하는게 아니면 freopen 열어라
	freopen("input_test.txt", "r", stdin);
#endif

#ifdef _WIN32 //window에서 돌리는거면 파일을 열어라, linux 서버이면 안연다.
	freopen("input_test.txt", "r", stdin);
#endif

	int a;
	long long b; // 잘 안쓰긴 함
	char c;
	char s[100];

	scanf("%d",&a);
	printf("%d\n", a);

	scanf("%lld", &b);
	printf("%lld\n", b);

	scanf(" %c", &c); //엔터, 공백 무시
	printf("%c\n", c);

	scanf(" %s", s); //문자열 뒤에 NULL값 붙여서 저장되기에 1자리 여유로워야함
	s[3] = 0; // 0은 NULL로 인식되어 [0,1,2] 문자열까지만 출력됨
	printf("%s\n", s);


	int arr[100] = {};
	for (int i = 1; i < 100; i++) {
		arr[i] = i;
		arr[i] += arr[i - 1];
	}
	printf("%d\n", arr[99]);

	return 0;
}
