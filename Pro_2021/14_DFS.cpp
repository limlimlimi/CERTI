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

//���
//#1 1 2 4 8 5 6 3 7 // �湮�� ���� ����

#define MAX_VERTEX 30

int vertex_dfs;
int map_dfs[MAX_VERTEX][MAX_VERTEX]; //0:������������ , 1:����
int visit_dfs[MAX_VERTEX]; //0:�湮�������� , 1:�湮��������

void depthFirstSearch(int v)
{
    int i;
    visit_dfs[v] = 1;
    for (i = 1; i <= vertex_dfs; i++)
    {
        if (map_dfs[v][i] == 1 && !visit_dfs[i]) //�����Ͽ���, �湮������ ������,
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

        cin >> vertex_dfs; //������ ����
        cin >> start; //���� ����

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