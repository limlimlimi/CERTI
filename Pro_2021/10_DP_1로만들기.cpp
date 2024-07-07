#define _CRT_SECURE_NO_WARNINGS //freopen error 때문에 사용
#include<iostream>
#include<ctime>
//#include<cstdio>
#include<algorithm>
using namespace std;

#define MAX_N 1000000 //(1<=N<=1,000,000)
//const int MAX_N = 1000000;

int cnt;
int dp1[MAX_N]; //index 값을 1로 만드는 최소연산횟수

int f(int N)
{
	if (N == 1)
		return 0;

	if (dp1[N] != -1) //dp에 값이 있으면 반환하고 끝
		return dp1[N];

	// dp에 값이 없으면 계산하고 반환
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
	// 시작 시간
	clock_t startTime = clock();

	int N;
	cin >> N;

	fill(dp1, dp1 + MAX_N, -1);
	cout << "1로 만드는 가장 적은 연산 횟수 : "<< f(N) << endl;

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

	// 종료 시간
	clock_t endTime = clock();

	// Millisecond
	clock_t elapsed = endTime - startTime;

	// Second
	double timeInSecond = (double)(elapsed / CLOCKS_PER_SEC);

	cout << "Elapsed: " << timeInSecond << "s(" << elapsed << "ms)" << "\n";

	return 0;
}