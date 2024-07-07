#define _CRT_SECURE_NO_WARNINGS //freopen error ������ ��µ� ȿ������
#include<iostream>
#include<vector>
using namespace std;

//�Ｚ ���� Graph : �� ������ ������ ������ �������� ���
//���� ���� Tree and Query : �� ������ ���� ���� SubTree ��� ������ ���
//210613 �Ｚ ��Ÿ�Ϸδ� �����ؼ� ���ϰڴ�, vector STL �����ϴ� ����� ���� ����

#define MAX_V 100001

//vector<int> v[MAX_V]; // 2���� vector �����Ŀ� ���� ������� �ٸ���
vector<vector<int>> v_graph(MAX_V);

int main_Graph()
{
	int s, e;
	int T, tc;
	int N, E, Q;

	//freopen("5_Tree_and_Query.txt", "r", stdin);
	freopen("5_Graph.txt", "r", stdin);

	//1. TestCase ���� �Է¹ޱ�
	//cout << "Enter Test Case : ";
	cin >> T;

	for (tc = 1; tc <= T; ++tc)
	{
		cin >> N; // Tree vertex ������ ����
		cin >> E; // Edge ���� ����
		cin >> Q; // Query�� ����
		
		for (int i = 0; i < E; i++)
		{
			cin >> s >> e;
			v_graph[s].push_back(e);
			v_graph[e].push_back(s);
		}

		//���
		cout << "\n #" << tc << "\n";

		//�Ｚ ���� ����
		for (int i = 0; i < Q; i++)
		{
			cin >> s;
			cout << s << "������ ������ �������� = ";
			for (int j = 0; j < v_graph[s].size(); j++)
			{
				cout << v_graph[s][j] << " ";
			}
			cout << endl;
		}
		// clear vector
		//v.clear(); //not working
		//v.resize(0, vector<int>(0, 0)); //not working
		for (int y = 0; y < v_graph.size(); ++y)
		{ 
			v_graph[y].clear();
		} 
	}

	return 0;
}