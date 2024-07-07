/*
13_������ �簢��
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
using namespace std;
//���� - �ڵ� ���� ������ - �������� - .snippet

#define MAX_NUM 5
void ps(int n) {
	int arr1[MAX_NUM];
	int arr2[MAX_NUM][MAX_NUM];

	cout << "sizeof(arr1[5]) : " << sizeof(arr1) << endl; //4Byte(int) * 5
	cout << "sizeof(arr2[5][5]) : " << sizeof(arr2) << endl; //4Byte(int) * 25

	//�迭 �ʱ�ȭ ��� 2����
	//fill_n(�迭�̸�,�ʱ�ȭ ��� ����, �ʱ�ȭ ��)
	fill_n(arr1, 5, 0);
	for (int i = 0; i < 5; i++) {
		cout << arr1[i] <<" " ;
	}
	cout << endl;

	//void memset(void* ptr, int value, size_t num)
	//void* ptr : �ʱ�ȭ�ϰ��� �ϴ� �޸��� ���� �ּ�
	//value : �ʱ�ȭ�ϰ��� �ϴ� ��
	//size_t num : ���� (sizeof(������Ÿ��)*����)
	//memset�� 1Byte ������ �ʱ�ȭ�ϱ� ������ 4Byte int ���ڴ� ǥ���� �� ����
	// memset�� 0�� -1�� �ʱ�ȭ ����

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
#ifndef ONLINE_JUDGE //IF NOT Define : ONLINE_JUDGE ���� �����ϴ°� �ƴϸ� freopen �����
	freopen("input_12.txt", "r", stdin);
#endif

#ifdef _WIN32 //window���� �����°Ÿ� ������ �����, linux �����̸� �ȿ���.
	freopen("input_12.txt", "r", stdin);
#endif

	int n;
	cin >> n;

	ps(n);

	return 0;
}
