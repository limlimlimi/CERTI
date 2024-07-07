#define _CRT_SECURE_NO_WARNINGS //freopen error ������ ��µ� ȿ������
#include<iostream>
using namespace std;

//210515

//�Է�
//1 //test case ����
//8 1 // ������ ����, ���� ����
//1 2 // ���� �� ���� ����. 1�� 2�� ����
//1 3
//2 4
//2 5
//4 8
//5 8
//3 6
//3 7
//6 8
//7 8
//- 1 - 1 // �Է� ��

// ���
// #1 1 2 3 4 5 6 7 8 // �湮�� ���� ����

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
    cout << vertex <<" "; //�湮�Ҷ����� ���
    queue_bfs[rear_bfs++] = vertex; //�ǵڿ� ���ְ�
    while (front_bfs < rear_bfs)
    {
        vertex = queue_bfs[front_bfs++];
        for (i = 1; i <= num_bfs; i++) //num_bfs ������ ����
        {
            //"queue_bfs �Ǿ� ����"�� ������ i������ �ְ�, �湮������ ������ => �湮�ϰ�, ����ϰ�, queue_bfs �ǵڿ� ���ְ�
            if (map_bfs[vertex][i] == 1 && !visit_bfs[i]) 
            {
                visit_bfs[i] = 1;
                cout << i << " ";//�湮�Ҷ����� ���
                queue_bfs[rear_bfs++] = i; //�ǵڿ� ���ְ�
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

        cin >> num_bfs;  //������ ����
        cin >> start; //���� ����

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