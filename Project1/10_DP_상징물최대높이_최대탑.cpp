// 1. 6 ���� �޾Ƽ� ���� ��տ� ����
// 2. �״��� 4¥�� ��� ���ʿ� ���ؼ� 8���� ũ�� 4�ڸ� ������ ������� �ѱ�
// 3. 3¥�� ��� ���ʿ� ���ؼ� 8���� ũ�� ������ ������� �ѱ�
// 4. 2¥�� ��� ���ʿ� ���ϰ� 8�̶� �����ϱ� ������ �׸� �װ�
// 5. ������ ���� �����ʿ� �� ����
// ���������� �����̶� ������ ���ؼ� ū�ŷ� �����ϸ� �� ?

// 1 2 3 4 6
// 6 + 2 = 4 + 3 + 1

// 1 2 3 4 7
// 7 + 1 = 4 + 3 + 2
// 7 = 4+ 3

#define _CRT_SECURE_NO_WARNINGS //freopen error ������ ���
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
	// ���� �ð�
	clock_t startTime = clock();

	freopen("10_DP_��¡���ִ����_�ִ�ž.txt", "r", stdin);
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

			// case1) block�� �Ƚ״°��
			//cout << "�Ƚ״� ��� : dp[i][j]       ,       dp[i - 1][j] \n";
			//cout << setw(18) << "dp[" << i << "][" << j << "]= " << dp[i][j];
			//cout << setw(15) << "dp[" << i - 1 << "][" << j << "]= " << dp[i - 1][j];
			dp[i][j] = max(dp[i][j], dp[i - 1][j]);
			//cout << "-> ��� : dp[" << i << "][" << j << "]= " << dp[i][j] << " \n\n";

			// case2) block�� ����ž�� �״� ���
			if (j + top[i] <= half)
			{
				//cout << "����ž ��� : dp[i][j+top[i]]       ,       dp[i - 1][j]+top[i] \n";
				//cout << setw(18) << "dp[" << i << "]["<< j << " + " << top[i] << "]= " << dp[i][j + top[i]];
				//cout << setw(15) << "dp[" << i - 1 << "][" << j << "]+ " << top[i] << "= " << dp[i][j] + top[i];
				dp[i][j + top[i]] = max(dp[i][j + top[i]], dp[i - 1][j] + top[i]);
				//cout << "-> ��� : dp[" << i << "][" << j + top[i] << "]= " << dp[i][j + top[i]] << " \n\n";
			}

			// case3) block�� ����ž�� �״°��
			if (abs(top[i] - j) <= half)
			{
				if (j < top[i]) // ����ž�� �ٲ�� ���
				{
					//cout << "����ž ��� 1 : dp[i][top[i] - j]       ,       dp[i - 1][j] \n";
					//cout << setw(18) << "dp[" << i << "]["<< top[i] << " - " << j << "]= " << dp[i][top[i] - j];
					//cout << setw(15) << "dp[" << i - 1 << "][" << j << "]+top[i]-j= " << (dp[i-1][j] + top[i] - j);
					dp[i][top[i] - j] = max(dp[i][top[i] - j], dp[i - 1][j] + top[i] - j);
					//cout << "-> ��� : dp[" << i << "][" << top[i] - j << "] = " << dp[i][top[i] - j] << " \n\n";
				}
				else // ����ž�� �״�� �����Ǵ� ���
				{
					//cout << "����ž ��� 2 : dp[i][top[i] - j]       ,       dp[i - 1][j] \n";
					//cout << setw(18) << "dp[" << i << "][" << j << " - " << top[i] << "]= " << dp[i][top[i] - j];
					//cout << setw(15) << "dp[" << i - 1 << "][" << j << "]= " << dp[i - 1][j];
					dp[i][j - top[i]] = max(dp[i][j - top[i]], dp[i - 1][j]);
					//cout << "-> ��� : dp[" << i << "][" << j  - top[i] <<"] = " << dp[i][j - top[i]] << " \n\n";
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

	// ���� �ð�
	clock_t endTime = clock();

	// Millisecond
	clock_t elapsed = endTime - startTime;

	// Second
	double timeInSecond = (double)(elapsed / CLOCKS_PER_SEC);

	cout << "Elapsed: " << timeInSecond << "s(" << elapsed << "ms)" << "\n";

	return 0;
}