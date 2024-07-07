#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
//#include <stdio.h>
//#include <stdlib.h>
using namespace std;

//N-QUEEN : ũ�Ⱑ NxN�� ü���� ���� �� N���� ���� ������ �� ������ ���� ����� ���� ���϶�
//���� ������ �� ���� : ���� ������ �� �� �ڽ��� �������� ��������(���� �� ����)�� �밢�� ���⿡�� �ƹ��͵� ���������� �� �ȴ�.
//DFS-Backtracking

//Input
//ù° �ٿ� N�� �־����ϴ�. (1 <= N < 15)

//Output
//�� N���� ���� ������ �� ���� ���� ����� ���� ����մϴ�.

int _count = 0;
int n;
int board[15];

// �������� �Ǵ��ϴ� �Լ�
int promising(int cdx) {

	// ���� ���̸� �ȵǰ�, �밢���� �־�� �� �ȴ�.
	for (int i = 0; i < cdx; i++) {
		if (board[cdx] == board[i] || cdx - i == abs(board[cdx] - board[i])) {
			return 0;
		}
	}
	return 1;
}

// nqueen �˰��� ����
void nqueen(int cdx) {

	// cdx�� ������ ����� �����ϰ� ������� ����, ã�� �Ϸ�
	if (cdx == n) {
		_count++;
		return;
	}

	for (int i = 0; i < n; i++) {
		board[cdx] = i; // cdx��° ��, i��° ���� queen�� ���ƺ���.	
		// ���� �� �࿡ �� �Ϳ� ���� �������� �Ǵ��Ѵ�.
		if (promising(cdx)) { // �� �ڸ��� �ξ �����Ҵٸ�,
			nqueen(cdx + 1); // �� ���� �࿡ ���� ���� ���� ���� �� ����.
		}
	}
}

int main_dfs_nqueen() {
	int tc;
	int T;

	freopen("16_DFS_Nqueen_input.txt", "r", stdin);
	cin >> T;

	for (tc = 1; tc <= T; ++tc)
	{

		/////////////////////////////////////////////////////////////////////////////////////////////
		cin >> n;

		_count = 0;
		nqueen(0);
		cout << "#" << tc << " ";
		cout << _count << endl;
		/////////////////////////////////////////////////////////////////////////////////////////////


	}
	return 0;
}