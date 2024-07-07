#define _CRT_SECURE_NO_WARNINGS //freopen error ������ ���
#include<iostream>
#include<cstring> //memset
#include<algorithm> //fill
#include<iomanip> //setw()
#include<ctime>
using namespace std;

#define MAX_N 100 //������ ���� , ����
#define MAX_K 10000 //���� ����

int dp_coin[MAX_N][MAX_K]; //������ �ּ� ����
int N_coin; //������ ����
int K_coin; // ���� ����
int cost_coin[MAX_N]; //�� ������ ��ġ

int coin(int n, int k)
{
	// ���������� ������ ���
	if (n == N_coin)
		//return 0;
		return (k == 0 ? 0 : MAX_K); //k���� 0�̸� ��, k���� ������ 0�� �ƴϸ� �Ұ���

	if (dp_coin[n][k] != -1)
	{
		cout << "coin(" << n << "," << k << ") = " << dp_coin[n][k] << endl;
		return dp_coin[n][k];
	}

	//1.���� �Ⱦ����
	int result = coin(n+1,k);

	//2.���� �� ���
	if (k >= cost_coin[n])
		result = min(result, coin(n, k - cost_coin[n]) + 1);
		// coin (n+1, k-cost[n]) + 1�� ������� �ʴ� ������ 
		// coin�� �ѹ��� ����ϴ� ���� �ƴ϶� ������ ����� �� �ֱ� ������ n���� �ٽ� ��Ȯ�� �ϴ� ��


	dp_coin[n][k] = result;
	return result;
}

int main_coin2()
{
	freopen("10_DP_����2.txt","r",stdin);
	cin >> N_coin; // ������ ���� ����
	cin >> K_coin; // ������ �� ��
	for (int i = 0; i < N_coin; i++)
		cin >> cost_coin[i];

	memset(dp_coin,-1,sizeof(dp_coin)); //cstring

	cout << "sizeof(dp_coin) = int (4) * MAX_N (100) * MAX_K (10000) = "<< sizeof(dp_coin) << endl;;
	cout << K_coin << "�� �� ����� ���� ������ �ּ� ���� : coin(0,K_coin) = " << coin(0, K_coin) << endl;

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