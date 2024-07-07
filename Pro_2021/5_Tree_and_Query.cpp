#define _CRT_SECURE_NO_WARNINGS //freopen error 때문에 사용
#include<iostream>
#include<ctime>
#include<vector>
using namespace std;

//삼성 문제 Graph : 각 쿼리의 정점에 인접한 정점들을 출력
//백준 문제 Tree and Query : 각 쿼리의 정점 하위 SubTree 노드 갯수를 출력

#define MAX_V 100001

vector<int> v[MAX_V];
//vector<vector<int>> v;
bool visit[MAX_V];

int num[MAX_V]; //subtree node 갯수
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
			continue;  // 아래 코드를 실행하지 않고 다음 for문 변수로 건너뜀
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

	cin >> N; // Tree vertex 정점의 갯수
	cin >> R; // Root 번호
	cin >> Q; // Query의 갯수

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

	//debugging is not working... 2차원 배열선언 방식에 따른 사용법 차이를 알아봐야할 듯
	//for (int y = 1; y < v.size(); y++)
	//{
	//	for (int x = 1; x <= v[y].size(); x++)
	//	{
	//		cout << "v[" << y << "][" << x << "] : " << v[y][x] << endl;
	//	}
	//	cout << endl;
	//}

	//백준 문제 정답
	for (int i = 0; i < Q; i++)
	{
		cin >> s;
		cout << s <<"정점 하위 Subtree 갯수 = "<< num[s] << endl;
	}

	finish = time(NULL);
	duration = (double)(finish - start);
	cout << "\n Measured Time : "<<duration << "초" << endl;


	return 0;
}