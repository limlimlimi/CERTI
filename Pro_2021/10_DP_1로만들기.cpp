#define _CRT_SECURE_NO_WARNINGS //freopen error ������ ���
#include<iostream>
#include<ctime>
//#include<cstdio>
#include<algorithm>
using namespace std;

#define MAX_N 1000000 //(1<=N<=1,000,000)
//const int MAX_N = 1000000;

int cnt;
int dp1[MAX_N]; //index ���� 1�� ����� �ּҿ���Ƚ��

int f(int N)
{
	if (N == 1)
		return 0;

	if (dp1[N] != -1) //dp�� ���� ������ ��ȯ�ϰ� ��
		return dp1[N];

	// dp�� ���� ������ ����ϰ� ��ȯ
	int result = f(N-1) + 1;
	if (N % 3 == 0)
		result = min( result, f(N/3) + 1);
	else if (N % 2 == 0)
		result = min(result, f(N/2) + 1);
	dp1[N] = result;

	return result;
}

int main_dp_making1()
{
	// ���� �ð�
	clock_t startTime = clock();

	int N;
	cin >> N;

	fill(dp1, dp1 + MAX_N, -1);
	cout << "1�� ����� ���� ���� ���� Ƚ�� : "<< f(N) << endl;

	int result = N , cnt = 0;
	//while (result != 1)
	//{
	//	if (result % 3 == 0)
	//		result = result / 3;
	//	else if (result % 2 == 0)
	//		result = result / 2;
	//	else
	//		result--;
	//	cnt++;
	//}

	// ���� �ð�
	clock_t endTime = clock();

	// Millisecond
	clock_t elapsed = endTime - startTime;

	// Second
	double timeInSecond = (double)(elapsed / CLOCKS_PER_SEC);

	cout << "Elapsed: " << timeInSecond << "s(" << elapsed << "ms)" << "\n";

	return 0;
}