#define _CRT_SECURE_NO_WARNINGS //freopen error 때문에 사용
#include <iostream>
using namespace std;
#define MAX_NODE 100

typedef struct listNode
{
    int data;
    struct listNode* prev;
    struct listNode* next;
} ListNode;

typedef struct
{
    int use;
    ListNode node;
} ListNodeHeap;

ListNodeHeap heap[MAX_NODE];

void initHeap(void)
{
    int i;
    for (i = 0; i < MAX_NODE; i++)
    {
        heap[i].use = 0;
    }
}

void initListNode(ListNode* node)
{
    node->data = 0;
    node->prev = node;
    node->next = node;
}

ListNode* getListNode(void)
{
    int i;
    for (i = 0; i < MAX_NODE; i++)
    {
        if (!heap[i].use)
        {
            heap[i].use = 1;
            initListNode(&heap[i].node);
            return &heap[i].node;
        }
    }
    return NULL;
}

void destroyListNode(ListNode* node)
{
    ListNodeHeap* heap_node = (ListNodeHeap*)((int*)node - 1);
    heap_node->use = 0;
}

ListNode* appendListNode(ListNode* list, int data)
{
    ListNode* node = getListNode();
    node->data = data;
    if (list == NULL)
    {
        return node;
    }
    else
    {
        ListNode* last = list->prev;
        last->next = node;
        list->prev = node;
        node->prev = last;
        node->next = list;
        return list;
    }
}

ListNode* removeListNode(ListNode* list, ListNode* node)
{
    if (list == list->next)
    {
        destroyListNode(node);
        return NULL;
    }
    else
    {
        ListNode* prev = node->prev;
        ListNode* next = node->next;
        prev->next = next;
        next->prev = prev;
        destroyListNode(node);
        return (list == node) ? next : list;
    }
}

//int main(int argc, char* argv[])
int main_Linked_list_ss()
{

    int T, N;

    freopen("6_Linked_List_ss.txt", "r", stdin);

    setbuf(stdout, NULL);
    cin >> T;

    for (int test_case = 1; test_case <= T; ++test_case)
    {
        ListNode* list = NULL;
        ListNode* node;
        int i;

        initHeap();

        cin >> N;
        for (i = 0; i < N; i++)
        {
            int data;
            cin >> data;
            list = appendListNode(list, data);
        }

        node = list;
        while (list != list->next)
        {
            ListNode* nextNode = node->next;
            list = removeListNode(list, node);
            node = nextNode->next->next;
        }

        //printf("#%d %d\n", test_case, list->data);
        cout <<"# "<< test_case <<" "<< list->data;
        cout << endl;
    }
    return 0;
}