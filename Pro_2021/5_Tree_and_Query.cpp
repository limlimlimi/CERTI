#define _CRT_SECURE_NO_WARNINGS //freopen error ������ ���
#include<iostream>
#include<ctime>
#include<vector>
using namespace std;

//�Ｚ ���� Graph : �� ������ ������ ������ �������� ���
//���� ���� Tree and Query : �� ������ ���� ���� SubTree ��� ������ ���

#define MAX_V 100001

vector<int> v[MAX_V];
//vector<vector<int>> v;
bool visit[MAX_V];

int num[MAX_V]; //subtree node ����
int s, e;

int dfs(int n)
{
	//debugging
	cout << " - ( " << n << " )" ;

	if(num[n]!=0)
		return num[n];

	visit[n] = true;

	int cnt = 1;
	for (int i = 0; i < v[n].size(); i++)
	{
		int next = v[n][i];
		if (visit[next] == true)
		{
			continue;  // �Ʒ� �ڵ带 �������� �ʰ� ���� for�� ������ �ǳʶ�
		}
		cnt += dfs(next);
	}

	num[n] = cnt;
	return cnt;
}

int main_tree_and_query()
{
	time_t start, finish;
	double duration;
	start = time(NULL);

	int N, R, Q;

	freopen("5_Tree_and_Query.txt", "r", stdin);

	cin >> N; // Tree vertex ������ ����
	cin >> R; // Root ��ȣ
	cin >> Q; // Query�� ����

	for (int i = 0; i < N - 1; i++)
	{
		cin >> s >> e;
		v[s].push_back(e);
		v[e].push_back(s);
	}

	//debugging
	cout << "Entered dfs recursion sequence ";

	num[R] = dfs(R);
	cout << endl;

	//debugging
	for (int i = 1; i <= N; i++)
	{
		cout << "Num[" <<i<<"] :"<<num[i] << " --- ";
		cout << "visit[" << i << "] :" << visit[i] << " --- ";
		cout << "v(" << i << ").size() : " << v[i].size() << endl;
	}
	cout << endl;

	//debugging is not working... 2���� �迭���� ��Ŀ� ���� ���� ���̸� �˾ƺ����� ��
	//for (int y = 1; y < v.size(); y++)
	//{
	//	for (int x = 1; x <= v[y].size(); x++)
	//	{
	//		cout << "v[" << y << "][" << x << "] : " << v[y][x] << endl;
	//	}
	//	cout << endl;
	//}

	//���� ���� ����
	for (int i = 0; i < Q; i++)
	{
		cin >> s;
		cout << s <<"���� ���� Subtree ���� = "<< num[s] << endl;
	}

	finish = time(NULL);
	duration = (double)(finish - start);
	cout << "\n Measured Time : "<<duration << "��" << endl;


	return 0;
}