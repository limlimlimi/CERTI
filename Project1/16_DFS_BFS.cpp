// #define _CRT_SECURE_NO_WARNINGS
// #include<iostream>
// using namespace std;
// 
// #define MAX_VERTEX 1050
// 
// int num_of_vertex;
// int map_bfs[MAX_VERTEX][MAX_VERTEX];
// int visit_bfs[MAX_VERTEX];
// int queue[MAX_VERTEX];
// int rear, front;
// 
// void bfs(int vertex)
// {
// 	int i;
// 	visit_bfs[vertex] = 1; //start vertex 방문하고
// 	cout << vertex; //start vertex 출력
// 	queue[rear++] = vertex; //queue 넣기
// 	while(front<rear)
// 	{
// 		vertex = queue[front++];
// 		for (i = 1; i <= num_of_vertex; i++)
// 		{
// 			if (map_bfs[vertex][i] == 1 && visit_bfs[i] != 1) //인접하고, 방문한적없고
// 			{
// 				visit_bfs[i] = 1;
// 				cout << " "<< i;
// 				queue[rear++] = i;
// 			}
// 		}
// 	}
// }
// 
// int map_dfs[MAX_VERTEX][MAX_VERTEX];
// int visit_dfs[MAX_VERTEX];
// int stack_dfs[MAX_VERTEX];
// int index_dfs;
// 
// // void dfs_recursion(int vertex)
// // {
// // 	int i;
// // 	visit_dfs[vertex] = 1; //start vertex 방문하고
// // 	//cout << vertex; //start vertex 출력하고싶으나 재귀방식에서는 중복되어버림
// // 	for (i = 1; i <= num_of_vertex; i++)
// // 	{
// // 		if (map_dfs[vertex][i] == 1 && visit_dfs[i] != 1)
// // 		{
// // 			cout << i<<" ";
// // 			dfs_recursion(i);
// // 		}
// // 	}
// // 	cout << endl;
// // }
// 
// void dfs_recursion(int vertex)
// {
// 	int i;
// 	if (visit_dfs[vertex] != 1)
// 	{
// 		visit_dfs[vertex] = 1; //start vertex 방문하고
// 		cout << vertex <<" ";
// 	}
// 	for (i = 1; i <= num_of_vertex; i++)
// 	{
// 		if (map_dfs[vertex][i] == 1 && visit_dfs[i] != 1)
// 		{
// 			visit_dfs[i] = 1;
// 			cout << i << " ";
// 			dfs_recursion(i);
// 		}
// 	}
// }
// 
// int pop()
// {
// 	int temp = stack_dfs[--index_dfs];
// 	stack_dfs[index_dfs] = 0;
// 	return temp;
// }
// 
// void push(int vertex)
// {
// 	stack_dfs[index_dfs++] = vertex;
// }
// 
// void dfs_stack(int vertex)
// {
// 	int i;
// 
// 	push(vertex);
// 	while (index_dfs!=0)
// 	{
// 		vertex = pop();
// 		if (visit_dfs[vertex] != 1)
// 		{
// 			visit_dfs[vertex] = 1;
// 			cout << vertex << " ";
// 		}
// 		for (i = num_of_vertex; i >=1 ; i--)
// 		{
// 			if (map_dfs[vertex][i] == 1 && visit_dfs[vertex] != 1)
// 				push(i);
// 		}
// 	}
// 	cout << endl;
// }
// 
// int main()
// {
// 	int i, j;
// 	int num_of_edge;
// 	int start;
// 	int v1, v2;
// 
// 	freopen("16_DFS_BFS.txt", "r", stdin);
// 	//freopen("output.txt", "w", stdout);
// 
// 	cin >> num_of_vertex; //N
// 	cin >> num_of_edge; //M
// 	cin >> start; //V
// 
// 	//bfs , dfs 초기화
// 	front = rear = 0;
// 	index_dfs = 0;
// 	for (i = 1; i <= num_of_vertex; i++)
// 	{
// 		for (j = 1; j <= num_of_vertex; j++)
// 		{
// 			map_bfs[i][j] = map_bfs[j][i] = 0;
// 			map_dfs[i][j] = map_dfs[j][i] = 0;
// 		}
// 		visit_bfs[i] = 0;
// 		queue[i] = 0;
// 		visit_dfs[i] = 0;
// 		stack_dfs[i] = 0;
// 	}
// 
// 	//while (cin >> v1)
// 	//{
// 	//	cin >> v2;
// 	//	map_bfs[v1][v2] = map_bfs[v2][v1] = 1;
// 	//	map_dfs[v1][v2] = map_dfs[v2][v1] = 1;
// 	//}
// 
// 	for(int k=1; k<=num_of_edge; k++)
// 	{
// 		cin >> v1;
// 		cin >> v2;
// 		map_bfs[v1][v2] = map_bfs[v2][v1] = 1;
// 		map_dfs[v1][v2] = map_dfs[v2][v1] = 1;
// 	}
// 
// 	//cout << start <<" "; //재귀방식 dfs의 경우 start vertex 출력을 여기서 할 수 도 있음
// 	//dfs_recursion(start);
// 	dfs_stack(start);
// 	bfs(start);
// 
// 
// 	return 0;
// }
