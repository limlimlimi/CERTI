#define _CRT_SECURE_NO_WARNINGS //freopen error 때문에 썼는데 효과있음
#include<iostream>
#include<vector>
using namespace std;

//삼성 문제 Graph : 각 쿼리의 정점에 인접한 정점들을 출력
//백준 문제 Tree and Query : 각 쿼리의 정점 하위 SubTree 노드 갯수를 출력
//210613 삼성 스타일로는 조급해서 못하겠다, vector STL 구현하는 방법을 익혀 쓰자

#define MAX_V 100001

//vector<int> v[MAX_V]; // 2차원 vector 선언방식에 따라서 사용방법이 다르다
vector<vector<int>> v_graph(MAX_V);

int main_Graph()
{
	int s, e;
	int T, tc;
	int N, E, Q;

	//freopen("5_Tree_and_Query.txt", "r", stdin);
	freopen("5_Graph.txt", "r", stdin);

	//1. TestCase 갯수 입력받기
	//cout << "Enter Test Case : ";
	cin >> T;

	for (tc = 1; tc <= T; ++tc)
	{
		cin >> N; // Tree vertex 정점의 갯수
		cin >> E; // Edge 간선 갯수
		cin >> Q; // Query의 갯수
		
		for (int i = 0; i < E; i++)
		{
			cin >> s >> e;
			v_graph[s].push_back(e);
			v_graph[e].push_back(s);
		}

		//출력
		cout << "\n #" << tc << "\n";

		//삼성 문제 정답
		for (int i = 0; i < Q; i++)
		{
			cin >> s;
			cout << s << "정점과 인접한 정점들은 = ";
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