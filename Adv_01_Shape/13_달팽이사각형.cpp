/*
13_달팽이 사각형
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
using namespace std;
//도구 - 코드 조각 관리자 - 가져오기 - .snippet

#define MAX_NUM 5
void ps(int n) {
	int arr1[MAX_NUM];
	int arr2[MAX_NUM][MAX_NUM];

	cout << "sizeof(arr1[5]) : " << sizeof(arr1) << endl; //4Byte(int) * 5
	cout << "sizeof(arr2[5][5]) : " << sizeof(arr2) << endl; //4Byte(int) * 25

	//배열 초기화 방법 2가지
	//fill_n(배열이름,초기화 요소 개수, 초기화 값)
	fill_n(arr1, 5, 0);
	for (int i = 0; i < 5; i++) {
		cout << arr1[i] <<" " ;
	}
	cout << endl;

	//void memset(void* ptr, int value, size_t num)
	//void* ptr : 초기화하고자 하는 메모리의 시작 주소
	//value : 초기화하고자 하는 값
	//size_t num : 길이 (sizeof(데이터타입)*길이)
	//memset은 1Byte 단위로 초기화하기 때문에 4Byte int 숫자는 표현할 수 없음
	// memset은 0과 -1로 초기화 가능

	memset(arr1,-1, sizeof(arr1)); //<string.h> or <memory.h>
	for (int i = 0; i < 5; i++) {
		cout << arr1[i] << " ";
	}
	cout << endl;

	memset(arr2, 0, sizeof(int) * MAX_NUM * MAX_NUM);
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			cout << arr2[i][j] << " " ;
		}
		cout << endl;
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
