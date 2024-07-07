#define _CRT_SECURE_NO_WARNINGS //freopen error 때문에 사용
#include<iostream>
#include<cstring> //memset
#include<algorithm> //fill
#include<iomanip> //setw()
#include<ctime>
using namespace std;

#define MAX_N 100 //동전의 종류 , 갯수
#define MAX_K 10000 //동전 총합

int dp_coin[MAX_N][MAX_K]; //동전의 최소 갯수
int N_coin; //동전의 종류
int K_coin; // 동전 총합
int cost_coin[MAX_N]; //각 동전의 가치

int coin(int n, int k)
{
	// 종료지점에 도달한 경우
	if (n == N_coin)
		//return 0;
		return (k == 0 ? 0 : MAX_K); //k값이 0이면 끝, k값이 아직도 0이 아니면 불가능

	if (dp_coin[n][k] != -1)
	{
		cout << "coin(" << n << "," << k << ") = " << dp_coin[n][k] << endl;
		return dp_coin[n][k];
	}

	//1.동전 안쓸경우
	int result = coin(n+1,k);

	//2.동전 쓸 경우
	if (k >= cost_coin[n])
		result = min(result, coin(n, k - cost_coin[n]) + 1);
		// coin (n+1, k-cost[n]) + 1을 사용하지 않는 이유는 
		// coin을 한번만 사용하는 것이 아니라 여러번 사용할 수 있기 때문에 n부터 다시 재확인 하는 것


	dp_coin[n][k] = result;
	return result;
}

int main_coin2()
{
	freopen("10_DP_동전2.txt","r",stdin);
	cin >> N_coin; // 동전의 종류 갯수
	cin >> K_coin; // 동전의 총 합
	for (int i = 0; i < N_coin; i++)
		cin >> cost_coin[i];

	memset(dp_coin,-1,sizeof(dp_coin)); //cstring

	cout << "sizeof(dp_coin) = int (4) * MAX_N (100) * MAX_K (10000) = "<< sizeof(dp_coin) << endl;;
	cout << K_coin << "원 을 만들기 위한 동전의 최소 갯수 : coin(0,K_coin) = " << coin(0, K_coin) << endl;

	for (int j = 0; j <= K_coin; j++)
		cout << "    [" << j << "]    ";
	cout << endl;

	for (int i = 0; i <= N_coin; i++)
	{
		for (int j = 0; j <= K_coin; j++)
			cout << setw(9)<< dp_coin[i][j] << "  ";
		cout << endl;
	}

	return 0;
}