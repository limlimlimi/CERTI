// 1. 6 부터 받아서 왼쪽 기둥에 더함
// 2. 그다음 4짜리 기둥 왼쪽에 더해서 8보다 크면 4자리 오른쪽 기둥으로 넘김
// 3. 3짜리 기둥 왼쪽에 더해서 8보다 크면 오른쪽 기둥으로 넘김
// 4. 2짜리 기둥 왼쪽에 더하고 8이랑 같으니까 왼쪽은 그만 쌓고
// 5. 남은거 전부 오른쪽에 다 더함
// 마지막으로 왼쪽이랑 오른쪽 비교해서 큰거로 리턴하면 끝 ?

// 1 2 3 4 6
// 6 + 2 = 4 + 3 + 1

// 1 2 3 4 7
// 7 + 1 = 4 + 3 + 2
// 7 = 4+ 3

#define _CRT_SECURE_NO_WARNINGS //freopen error 때문에 사용
#include<iostream>
//#include<algorithm>
#include<iomanip> //setw(10)
#include<cstring> //memset
#include<ctime>
using namespace std;

int n2, top[50], sum = 0;
int dp[50][250001];

int main_top()
{
	// 시작 시간
	clock_t startTime = clock();

	freopen("10_DP_상징물최대높이_최대탑.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n2;
	for (int i = 0; i < n2; i++)
	{
		cin >> top[i];
		sum += top[i];
	}
	int half = sum / 2;
	memset(dp, -1, sizeof(dp));
	dp[0][0] = 0;
	dp[0][top[0]] = top[0];

	cout << "dp[i][j] initialization result : \n";
	for (int i = 0; i < n2; i++)
	{
		for (int j = 0; j <= half; j++)
		{
			cout << "dp[" << i << "][" << j << "]=" << setw(10) << dp[i][j] << " ";
		}
		cout << endl;
	}
	cout << "\n\n";

	for (int i = 1; i < n2; i++)
	{
		for (int j = 0; j <= half; j++)
		{
			if (dp[i - 1][j] == -1)
				continue;
			//cout << "i=" << i << " , j= " << j << " , top[i] = " << top[i] << endl;

			// case1) block을 안쌓는경우
			//cout << "안쌓는 경우 : dp[i][j]       ,       dp[i - 1][j] \n";
			//cout << setw(18) << "dp[" << i << "][" << j << "]= " << dp[i][j];
			//cout << setw(15) << "dp[" << i - 1 << "][" << j << "]= " << dp[i - 1][j];
			dp[i][j] = max(dp[i][j], dp[i - 1][j]);
			//cout << "-> 결과 : dp[" << i << "][" << j << "]= " << dp[i][j] << " \n\n";

			// case2) block을 높은탑에 쌓는 경우
			if (j + top[i] <= half)
			{
				//cout << "높은탑 경우 : dp[i][j+top[i]]       ,       dp[i - 1][j]+top[i] \n";
				//cout << setw(18) << "dp[" << i << "]["<< j << " + " << top[i] << "]= " << dp[i][j + top[i]];
				//cout << setw(15) << "dp[" << i - 1 << "][" << j << "]+ " << top[i] << "= " << dp[i][j] + top[i];
				dp[i][j + top[i]] = max(dp[i][j + top[i]], dp[i - 1][j] + top[i]);
				//cout << "-> 결과 : dp[" << i << "][" << j + top[i] << "]= " << dp[i][j + top[i]] << " \n\n";
			}

			// case3) block을 낮은탑에 쌓는경우
			if (abs(top[i] - j) <= half)
			{
				if (j < top[i]) // 높은탑이 바뀌는 경우
				{
					//cout << "낮은탑 경우 1 : dp[i][top[i] - j]       ,       dp[i - 1][j] \n";
					//cout << setw(18) << "dp[" << i << "]["<< top[i] << " - " << j << "]= " << dp[i][top[i] - j];
					//cout << setw(15) << "dp[" << i - 1 << "][" << j << "]+top[i]-j= " << (dp[i-1][j] + top[i] - j);
					dp[i][top[i] - j] = max(dp[i][top[i] - j], dp[i - 1][j] + top[i] - j);
					//cout << "-> 결과 : dp[" << i << "][" << top[i] - j << "] = " << dp[i][top[i] - j] << " \n\n";
				}
				else // 높은탑은 그대로 유지되는 경우
				{
					//cout << "낮은탑 경우 2 : dp[i][top[i] - j]       ,       dp[i - 1][j] \n";
					//cout << setw(18) << "dp[" << i << "][" << j << " - " << top[i] << "]= " << dp[i][top[i] - j];
					//cout << setw(15) << "dp[" << i - 1 << "][" << j << "]= " << dp[i - 1][j];
					dp[i][j - top[i]] = max(dp[i][j - top[i]], dp[i - 1][j]);
					//cout << "-> 결과 : dp[" << i << "][" << j  - top[i] <<"] = " << dp[i][j - top[i]] << " \n\n";
				}
			}

			//cout << "dp[i][j] debugging result : \n";
			//for (int i = 0; i < n2; i++)
			//{
			//	for (int j = 0; j <= half; j++)
			//	{
			//		cout << "dp[" << i << "][" << j << "]=";
			//		if (dp[i][j] != -1)
			//			cout << setw(10) << dp[i][j] << " ";
			//		else
			//			cout << setw(10) << "---------- ";
			//	}
			//	cout << endl;
			//}
			//cout << "\n\n";
			//cout << "-------------------------------------------------------------------------------------\n";
		}
	}
	if (dp[n2 - 1][0] == -1)
		cout << "-1" << endl;
	else
		cout << dp[n2 - 1][0] << endl;

	cout << "top[i] Final result : \n";
	for (int i = 0; i < n2; i++)
	{
		cout << "top[" << i << "]=" << top[i] << " ";
	}
	cout << "\n\n";

	cout << "dp[i][j] Final result : \n";
	for (int i = 0; i < n2; i++)
	{
		for (int j = 0; j <= half; j++)
		{
			cout << "dp[" << i << "][" << j << "]=" << setw(10) << dp[i][j] << " ";
		}
		cout << endl;
	}
	cout << "\n\n";

	// 종료 시간
	clock_t endTime = clock();

	// Millisecond
	clock_t elapsed = endTime - startTime;

	// Second
	double timeInSecond = (double)(elapsed / CLOCKS_PER_SEC);

	cout << "Elapsed: " << timeInSecond << "s(" << elapsed << "ms)" << "\n";

	return 0;
}