#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

#define MAX_NODE_NUM 10000
#define MAX_CHILD_NUM 2

// 210514
// 트리 구조란 그래프의 일종으로, 여러 노드가 한 노드를 가리킬 수 없는 구조이다.
// 간단하게는 회로가 없고, 서로 다른 두 노드를 잇는 길이 하나뿐인 그래프를 트리라고 부른다.
// 주어진 입력 값으로 트리를 구성하고, 구성된 트리를 전위순회하고 방문한 노드의 번호를 출력하시오
// 첫 줄에는 전체 테스트 케이스의 수(T), 두 번째 줄에는 노드의 총 수(nodeNum), 간선의 총 수(edgeNum)가 주어진다.
// 그 다음 줄에는 간선이 나열 된다.간선은 그것을 이루는 두 정점으로 표기된다.
// 간선은 항상 “부모 자식” 순서로 표기 된다.
// 예를 들어 “1 2”는 정점 1과 2를 잇는 간선을 의미하며 1이 부모 2가 자식을 의미한다.
// 부모는 최대 2개의 자식 노드를 갖으며, 최대 노드의 개수는 10000개이다.

// 입력
// 2 // Testcase 수
// 13 12 // N: 노드의 총 수, E: 간선의 총 수
// 1 2 1 3 2 4 3 5 3 6 4 7 7 12 5 9 5 8 6 11 6 10 11 13 // 간선 정보 (“부모 자식” 순서)
// 10 9
// 1 2 1 3 3 4 4 5 5 6 6 7 7 8 8 9 9 10

//출력
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
    
    //1. TestCase 갯수 입력받기
    //cout << "Enter Test Case : ";
    cin >> T;

    for (tc = 1; tc <= T; ++tc)
    {
        //2. 입력변수값 받기
        //cout << "Enter nodeNum : ";
        cin >> nodeNum;
        //cout << "Enter edgeNum : ";
        cin >> edgeNum;
        
        initTree();

        //3. Data 입력받기
        for (i = 0; i < edgeNum; i++)
        {
            //cout << "\nEnter parent : ";
            cin >> parent;
            //cout << "\nEnter edgeNum : ";
            cin >> child;
            addChild(parent, child);
        }

        root = getRoot();

        //4.출력
        cout << "\n#" << tc << " : ";
        preOrder(root);
        cout << endl;
    }
    return 0;
}