// #define _CRT_SECURE_NO_WARNINGS
// #include<iostream>
// #include<vector>
// using namespace std;
// #define MAX(a,b) (a>b?a:b)
// #define MAX_V 10001
// 
// // 우수마을
// // 문제 : 
// // N개마을 (정점)
// // N-1개 길 (간선)
// // 마을은 Tree구조이며 방향성 없음
// 
// // 우수마을 주민수 총합을 최대로 하는 우수마을의 인원을 구하라.
// // 우수마을 끼리는 인접 불가
// // 일반마을은 적어도 하나의 우수마을과 인접해야함
// 
// vector<int> cnt; //마을주민수
// vector<int> node[MAX_V]; //마을번호
// int N; // 마을 갯수
// 
// bool visit[MAX_V]; //트리구조를 직접 구현하지 않으면서도 트리탐색과 같이 쓰기위해 사용
// int dp[MAX_V][2]; //dp
// 
// void dfs(int cur)
// {
// 	if (visit[cur])
// 		return;
// 
// 	visit[cur] = true;
// 	dp[cur][0] = 0; //일반마을인 경우 우수마을의 인원을 구하는 dp에 더하지 않음
// 	dp[cur][1] = cnt[cur]; //우수마을인 경우 우수마을의 인원을 구하는 dp에 각 마을 구성원을 대입
// 
// 	//cout << "test "<<cur<<endl;
// 	//for (int i = 0; i < N; i++)
// 	//{
// 	//	int next = node[cur][i];
// 	//	if (visit[next])
// 	//		continue;
// 	//	dfs(next);
// 	//	dp[cur][0] += max(dp[next][1],dp[next][0]);
// 	//	dp[cur][1] += dp[next][0];
// 	//}
// 	for (int next : node[cur])
// 	{
// 		if (visit[next])
// 			continue;
// 		dfs(next);
// 		dp[cur][0] += max(dp[next][1], dp[next][0]);
// 		dp[cur][1] += dp[next][0];
// 	}
// }
// 
// int main()
// {
// 	//freopen("10_DP_Tree_input.txt", "r", stdin);
// 	freopen("DP_Tree_input.txt", "r", stdin);
// 	cin >> N; //입력받은 마을갯수
// 
// 	cnt.push_back(0); //x=[0]초기화
// 
// 	// cnt 마을 주민 수 입력받기
// 	for (int i = 0;i<N; i++ )
// 	{
// 		int input;
// 		cin >> input;
// 		cnt.push_back(input); //x=[1]부터 값 넣음
// 	}
// 	// node 마을 번호 입력받기
// 	for (int i = 0; i < N - 1; i++)
// 	{
// 		int a,b;
// 		cin >> a >> b;
// 		node[a].push_back(b);
// 		node[b].push_back(a);
// 	}
// 
// 	dfs(1); //어떤 노드를 호출해도 상관 없다고 함
// 	cout << max(dp[1][0], dp[1][1]) << endl;
// 
// 	//dfs(7); //어떤 노드를 호출해도 상관 없다고 함
// 	//cout << max(dp[7][0], dp[7][1]) << endl;
// 	
// 	return 0;
// }