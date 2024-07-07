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

// 출력
// #1 1 2 3 4 5 6 7 8 // 방문한 정점 순서

#define MAX_VERTEX 30

int num_bfs;
int map_bfs[MAX_VERTEX][MAX_VERTEX];
int visit_bfs[MAX_VERTEX];
int queue_bfs[MAX_VERTEX];
int rear_bfs, front_bfs;

void breadthFirstSearch(int vertex)
{
    int i;

    visit_bfs[vertex] = 1;
    cout << vertex <<" "; //방문할때마다 출력
    queue_bfs[rear_bfs++] = vertex; //맨뒤에 값넣고
    while (front_bfs < rear_bfs)
    {
        vertex = queue_bfs[front_bfs++];
        for (i = 1; i <= num_bfs; i++) //num_bfs 정점의 갯수
        {
            //"queue_bfs 맨앞 정점"과 인접한 i정점이 있고, 방문한적이 없으면 => 방문하고, 출력하고, queue_bfs 맨뒤에 값넣고
            if (map_bfs[vertex][i] == 1 && !visit_bfs[i]) 
            {
                visit_bfs[i] = 1;
                cout << i << " ";//방문할때마다 출력
                queue_bfs[rear_bfs++] = i; //맨뒤에 값넣고
            }
        }
    }
}

int main_bfs_basic(void)
{
    int T, tc, i, j;
    int start;
    int v1, v2;

    freopen("15_BFS.txt", "r", stdin);
    cin >> T;

    for (tc = 1; tc <= T; tc++)
    {

        for (i = 0; i < MAX_VERTEX; i++)
        {
            for (j = 0; j < MAX_VERTEX; j++)
            {
                map_bfs[i][j] = 0;
            }
            visit_bfs[i] = 0;
            queue_bfs[i] = 0;
        }
        front_bfs = 0;
        rear_bfs = 0;

        cin >> num_bfs;  //정점의 갯수
        cin >> start; //시작 정점

        while (true)
        {
            cin >> v1;
            cin >> v2;
            if (v1 == -1 && v2 == -1)
            {
                break;
            }
            map_bfs[v1][v2] = map_bfs[v2][v1] = 1;
        }

        cout << "# " << tc << " : ";
        breadthFirstSearch(start);
        cout << endl;
    }

    return 0;
}