#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

#define MAX_NODE_NUM 10000
#define MAX_CHILD_NUM 2

// 210514
// Ʈ�� ������ �׷����� ��������, ���� ��尡 �� ��带 ����ų �� ���� �����̴�.
// �����ϰԴ� ȸ�ΰ� ����, ���� �ٸ� �� ��带 �մ� ���� �ϳ����� �׷����� Ʈ����� �θ���.
// �־��� �Է� ������ Ʈ���� �����ϰ�, ������ Ʈ���� ������ȸ�ϰ� �湮�� ����� ��ȣ�� ����Ͻÿ�
// ù �ٿ��� ��ü �׽�Ʈ ���̽��� ��(T), �� ��° �ٿ��� ����� �� ��(nodeNum), ������ �� ��(edgeNum)�� �־�����.
// �� ���� �ٿ��� ������ ���� �ȴ�.������ �װ��� �̷�� �� �������� ǥ��ȴ�.
// ������ �׻� ���θ� �ڽġ� ������ ǥ�� �ȴ�.
// ���� ��� ��1 2���� ���� 1�� 2�� �մ� ������ �ǹ��ϸ� 1�� �θ� 2�� �ڽ��� �ǹ��Ѵ�.
// �θ�� �ִ� 2���� �ڽ� ��带 ������, �ִ� ����� ������ 10000���̴�.

// �Է�
// 2 // Testcase ��
// 13 12 // N: ����� �� ��, E: ������ �� ��
// 1 2 1 3 2 4 3 5 3 6 4 7 7 12 5 9 5 8 6 11 6 10 11 13 // ���� ���� (���θ� �ڽġ� ����)
// 10 9
// 1 2 1 3 3 4 4 5 5 6 6 7 7 8 8 9 9 10

//���
//#1
//1 2 4 7 12 3 5 9 8 6 11 13 10
//#2
//1 2 3 4 5 6 7 8 9 10

typedef struct
{
    int parent;
    int child[MAX_CHILD_NUM+1];
} TreeNode;
TreeNode tree[MAX_NODE_NUM+1];
int nodeNum;
int edgeNum;
int root;

void initTree(void)
{
    for (int i = 0; i <= nodeNum; i++)
    {
        tree[i].parent = -1;
        for (int j = 0; j < MAX_CHILD_NUM; j++)
        {
            tree[i].child[j] = -1;
        }
    }
}

void addChild(int parent, int child)
{
    int i;
    for ( i = 0; i < MAX_CHILD_NUM; i++)
    {
        if (tree[parent].child[i] == -1)
        {
            break;
        }
    }
    tree[parent].child[i] = child;
    tree[child].parent = parent;
    //debugging
    //cout << "\n addCihld Result 1 : tree[ " << parent << " ].child[ " << i << " ] = " << tree[parent].child[i];
    //cout << "\n addCihld Result 2 : tree[ " << child << " ].parent = " << tree[child].parent;
}

int getRoot(void)
{
    for (int i = 1; i <= nodeNum; i++)
    {
        if (tree[i].parent == -1)
        {
            //cout << "root in the getRoot function is " << i;
            return i;
        }
    }
    return -1;
}

void preOrder(int root)
{
    int child;
    cout << root << " ";

    for (int i = 0; i < MAX_CHILD_NUM; i++)
    {
        child = tree[root].child[i];
        if (child != -1)
        {
            preOrder(child);
        }
    }
}


int main_Tree()
{

    int tc;
    int T;
    int i;
    int parent;
    int child;

    freopen("4_Tree.txt", "r", stdin);
    
    //1. TestCase ���� �Է¹ޱ�
    //cout << "Enter Test Case : ";
    cin >> T;

    for (tc = 1; tc <= T; ++tc)
    {
        //2. �Էº����� �ޱ�
        //cout << "Enter nodeNum : ";
        cin >> nodeNum;
        //cout << "Enter edgeNum : ";
        cin >> edgeNum;
        
        initTree();

        //3. Data �Է¹ޱ�
        for (i = 0; i < edgeNum; i++)
        {
            //cout << "\nEnter parent : ";
            cin >> parent;
            //cout << "\nEnter edgeNum : ";
            cin >> child;
            addChild(parent, child);
        }

        root = getRoot();

        //4.���
        cout << "\n#" << tc << " : ";
        preOrder(root);
        cout << endl;
    }
    return 0;
}