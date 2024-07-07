#define _CRT_SECURE_NO_WARNINGS //freopen error ������ ���
#include<iostream>
using namespace std;

#define MAX_N 1000000 //(1<=N<=1,000,000)
#define MAX_M 2000000000 //(1<=M<=2,000,000,000) 
//const int MAX_N = 1000000; //(1 <= N <= 1, 000, 000)
//const int MAX_M = 2000000000; //(1 <= M <= 2, 000, 000, 000)
// (signed) int�� -20�� ~ +20��(2*10^9)���� ���� ���� 
// (signed) long long �� -(9*10^18) ~ +(9*10^18)���� ���� ����

// //�Է�
// 4 7
// 20 15 10 17
// //���
// 15

int main_bs_tree()
{
	int N; // ������ ����
	int M; // �ʿ��� (���� ���������� �ϴ�) �߶� ������ �� ��
	int tree[MAX_N];

	cin >> N >> M;
	for (int i = 0; i < N; i++)
		cin >> tree[i];

	int low = 0;
	int high = MAX_M; // ������ ���� ���� H = low�̸� ������ ����, H = high �̸� ������ �Ұ���

	while (low < high) // Ǯ�̿����� low+1 < high�� üũ�ϴ���...
	{
		int mid = (low + high) / 2; // �����鿡 ������ ���� H�� mid �� ��� ������ ã�� ���� ��
		long long sum = 0;
		for (int i = 0; i < N; i++)
			if(tree[i]>mid)
				sum += tree[i]-mid;
		if (sum >= M)
			low = mid;
		else
			high = mid;
	}
	cout << "������ ���� ���� H �� �ִ��� ( ������ ���ϰ� �ڸ��� �ʰ� �ʿ��� ��ŭ�� ������ �� �ִ� ������ ���� ���� ) : " << low;

	return 0;
}