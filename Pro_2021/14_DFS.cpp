#define _CRT_SECURE_NO_WARNINGS //freopen error 때문에 썼는데 효과있음
#include<iostream>
using namespace std;

//210515

//입력
//1 //test case 개수
//8 1 // 정점의 개수, 시작 정점
//1 2 // 정점 간 연결 관계. 1과 2가 연결
//1 3
//2 4
//2 5
//4 8
//5 8
//3 6
//3 7
//6 8
//7 8
//- 1 - 1 // 입력 끝

//출력
//#1 1 2 4 8 5 6 3 7 // 방문한 정점 순서

#define MAX_VERTEX 30

int vertex_dfs;
int map_dfs[MAX_VERTEX][MAX_VERTEX]; //0:인접하지않음 , 1:인접
int visit_dfs[MAX_VERTEX]; //0:방문한적없음 , 1:방문한적있음

void depthFirstSearch(int v)
{
    int i;
    visit_dfs[v] = 1;
    for (i = 1; i <= vertex_dfs; i++)
    {
        if (map_dfs[v][i] == 1 && !visit_dfs[i]) //인접하였고, 방문한적이 없으면,
        {
            cout << i<<" ";
            depthFirstSearch(i);
        }
    }
}

int main_dfs_basic(void)
{
    int T, tc, i, j;
    int start;
    int v1, v2;

    freopen("14_DFS.txt", "r", stdin);

    //cout << "Enter Test case T : ";
    cin >> T;

    for (tc = 1; tc <= T; tc++)
    {
        for (i = 0; i < MAX_VERTEX; i++)
        {
            for (j = 0; j < MAX_VERTEX; j++)
            {
                map_dfs[i][j] = 0;
            }
            visit_dfs[i] = 0;
        }

        cin >> vertex_dfs; //정점의 갯수
        cin >> start; //시작 정점

        while (true)
        {
            cin >> v1;
            cin >> v2;
            if (v1 == -1 && v2 == -1)
            {
                break;
            }
            map_dfs[v1][v2] = map_dfs[v2][v1] = 1;
        }

        cout << "# " << tc << " : ";
        cout << start << " ";
        depthFirstSearch(start);
        cout << endl;
    }

    return 0;
}