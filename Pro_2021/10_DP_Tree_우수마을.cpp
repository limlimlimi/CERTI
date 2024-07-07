#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
using namespace std;
#define MAX(a,b) (a>b?a:b)
#define MAX_V 10001

// �������
// ���� : 
// N������ (����)
// N-1�� �� (����)
// ������ Tree�����̸� ���⼺ ����

// ������� �ֹμ� ������ �ִ�� �ϴ� ��������� �ο��� ���϶�.
// ������� ������ ���� �Ұ�
// �Ϲݸ����� ��� �ϳ��� ��������� �����ؾ���

vector<int> cnt; //�����ֹμ�
vector<int> node[MAX_V]; //������ȣ
int N_vil2; // ���� ����

bool visit_vil[MAX_V]; //Ʈ�������� ���� �������� �����鼭�� Ʈ��Ž���� ���� �������� ���
int dp_vil[MAX_V][2]; //dp

void dfs(int cur)
{
	if (visit_vil[cur])
		return;

	visit_vil[cur] = true;
	dp_vil[cur][0] = 0; //�Ϲݸ����� ��� ��������� �ο��� ���ϴ� dp�� ������ ����
	dp_vil[cur][1] = cnt[cur]; //��������� ��� ��������� �ο��� ���ϴ� dp�� �� ���� �������� ����

	//cout << "test "<<cur<<endl;
	//for (int i = 0; i < N_vil2; i++)
	//{
	//	int next = node[cur][i];
	//	if (visit_vil[next])
	//		continue;
	//	dfs(next);
	//	dp_vil[cur][0] += max(dp_vil[next][1],dp_vil[next][0]);
	//	dp_vil[cur][1] += dp_vil[next][0];
	//}
	for (int next : node[cur])
	{
		if (visit_vil[next])
			continue;
		dfs(next);
		dp_vil[cur][0] += max(dp_vil[next][1], dp_vil[next][0]);
		dp_vil[cur][1] += dp_vil[next][0];
	}
}

int main_dp_tree_vil()
{
	//freopen("10_DP_Tree_input.txt", "r", stdin);
	freopen("10_DP_Tree_input.txt", "r", stdin);
	cin >> N_vil2; //�Է¹��� ��������

	cnt.push_back(0); //x=[0]�ʱ�ȭ

	// cnt ���� �ֹ� �� �Է¹ޱ�
	for (int i = 0;i<N_vil2; i++ )
	{
		int input;
		cin >> input;
		cnt.push_back(input); //x=[1]���� �� ����
	}
	// node ���� ��ȣ �Է¹ޱ�
	for (int i = 0; i < N_vil2 - 1; i++)
	{
		int a,b;
		cin >> a >> b;
		node[a].push_back(b);
		node[b].push_back(a);
	}

	dfs(1); //� ��带 ȣ���ص� ��� ���ٰ� ��
	cout << max(dp_vil[1][0], dp_vil[1][1]) << endl;

	//dfs(7); //� ��带 ȣ���ص� ��� ���ٰ� ��
	//cout << max(dp_vil[7][0], dp_vil[7][1]) << endl;
	
	return 0;
}