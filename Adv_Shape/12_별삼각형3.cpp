/*
���ﰢ��3
240701 MON
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
using namespace std;
//���� - �ڵ� ���� ������ - �������� - .snippet

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
			for (int j = 0; j < 2*i+1; j++) { //���� ������ ����ϴ� ��� �̰ű���!!
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
			for (int j = 0; j < 2*(n/2-i)-1; j++) { //���� ������ ����ϴ� ��� �̰ű���!!
				cout << "*"; 
			}

			//line feed
			cout << endl;
		}
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
