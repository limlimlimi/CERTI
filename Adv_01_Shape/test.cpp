/*
�����̸�
*/

/*
* VS ����
* ����
* Ctrl + F5 : �ڵ� ����
* Ctrl + Shift + A : ���ϻ���
* ������Ʈ��Ŭ��+ A : ������ƮȰ��ȭ
* ���Ͽ�Ŭ��+ R : ���ϼӼ� //main �Լ� �������� ���, .cpp - �Ӽ� - ���忡�� ���� : ��
* Ctrl + Shift + // : ���� �ּ� ó��
* Ctrl + K, C : �ؼ�(comment)
* Ctrl + K, U : �ؼ�����(comment out)
* Ctrl + D : �ٺ���
* Ctrl + L : �ٻ���
* Ctrl + �¿�, Del, �齺���̽� : �����̵�,����
*
*����� DEBUGGING
* Ctrl + F10 : ������ġ���� ����� ���� // debug - â - ����� ������ â ���� ����
* ������ġ���̵�
* F10: ���ٽ���(�Լ�����ħ)
* F11: ���ٽ���(�Լ���)
* Shift + F5 : �������� (����� ����)
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
using namespace std;

int main() {
#ifndef ONLINE_JUDGE //IF NOT Define : ONLINE_JUDGE ���� �����ϴ°� �ƴϸ� freopen �����
	freopen("input_test.txt", "r", stdin);
#endif

#ifdef _WIN32 //window���� �����°Ÿ� ������ �����, linux �����̸� �ȿ���.
	freopen("input_test.txt", "r", stdin);
#endif

	int a;
	long long b; // �� �Ⱦ��� ��
	char c;
	char s[100];

	scanf("%d",&a);
	printf("%d\n", a);

	scanf("%lld", &b);
	printf("%lld\n", b);

	scanf(" %c", &c); //����, ���� ����
	printf("%c\n", c);

	scanf(" %s", s); //���ڿ� �ڿ� NULL�� �ٿ��� ����Ǳ⿡ 1�ڸ� �����ο�����
	s[3] = 0; // 0�� NULL�� �νĵǾ� [0,1,2] ���ڿ������� ��µ�
	printf("%s\n", s);


	int arr[100] = {};
	for (int i = 1; i < 100; i++) {
		arr[i] = i;
		arr[i] += arr[i - 1];
	}
	printf("%d\n", arr[99]);

	return 0;
}
