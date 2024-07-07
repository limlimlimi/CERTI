#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
//#include <stdio.h>
//#include <stdlib.h>
using namespace std;

//N-QUEEN : 크기가 NxN인 체스판 위에 퀸 N개를 서로 공격할 수 없도록 놓는 경우의 수를 구하라
//서로 공격할 수 없다 : 퀸이 놓였을 때 퀸 자신을 기준으로 일직선상(가로 및 세로)과 대각선 방향에는 아무것도 놓여있으면 안 된다.
//DFS-Backtracking

//Input
//첫째 줄에 N이 주어집니다. (1 <= N < 15)

//Output
//퀸 N개를 서로 공격할 수 없게 놓는 경우의 수를 출력합니다.

int _count = 0;
int n;
int board[15];

// 유망한지 판단하는 함수
int promising(int cdx) {

	// 같은 열이면 안되고, 대각선상에 있어서도 안 된다.
	for (int i = 0; i < cdx; i++) {
		if (board[cdx] == board[i] || cdx - i == abs(board[cdx] - board[i])) {
			return 0;
		}
	}
	return 1;
}

// nqueen 알고리즘 수행
void nqueen(int cdx) {

	// cdx가 마지막 행까지 수행하고 여기까지 오면, 찾기 완료
	if (cdx == n) {
		_count++;
		return;
	}

	for (int i = 0; i < n; i++) {
		board[cdx] = i; // cdx번째 행, i번째 열에 queen을 놓아본다.	
		// 이후 그 행에 둔 것에 대한 유망성을 판단한다.
		if (promising(cdx)) { // 그 자리에 두어도 괜찮았다면,
			nqueen(cdx + 1); // 그 다음 행에 대해 퀸을 놓는 것을 해 본다.
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