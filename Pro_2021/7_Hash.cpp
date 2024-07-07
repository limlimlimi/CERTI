#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
#include<cstdio> // C����� stdio.h�� �����ϴ�. //����°� ���õ� ���� C�Լ����� ������ ��������Դϴ�. (printf(), fprintf(), fopen, etc)
#include<memory> //���� �޸𸮸� �����ϴ� �Լ��� ����ϱ� ���� �ۼ� : memcpy , memset , memcmp

// 210514

#define MAX_KEY 64
#define MAX_DATA 128
#define MAX_TABLE 4096

using namespace std;

//close Addressing ����� chaining��� �̿��� �ؽ� ���̺� ����
//Hash table�� Ű�� ���� ������ �� �ִ� ������, ���� �迭 �߰��� ���Ǵ� �ڷ� �����̴�. 
//Hash table�� Hash �Լ��� ����Ͽ� ����(index, Key)�� ��Ŷ(bucket)�̳� ����(slot)�� �迭�� ����Ѵ�.

//�־��� N���� key, data���� Hash table�� �Է��� ��, 
//Q���� key�� �Է� �޾� key�� �ش��ϴ� data�� �� �ٿ� ����Ͻÿ�. (1 <= N, Q <= 4096)
//* Key : �ִ� 64���� ���ڿ�
//* Data : �ִ� 128���� ���ڿ�

//�Է� (key)
//123123
//123
//23
//4
//serf

//��� (data)
//234
//sdf
//df
//gd
//cvb

typedef struct
{
    char key[MAX_KEY + 1];
    char data[MAX_DATA + 1];
}HashNode;
HashNode tb[MAX_TABLE];

unsigned long hashfunction(const char* str)
{
    unsigned long hash = 5381;
    int c;

    while (c = *str++)
    {
        hash = (((hash) +hash) + c) % MAX_TABLE;
    }

    return hash % MAX_TABLE;
}

int find(const char* key, char* data)
{
    unsigned long h = hashfunction(key);
    int cnt = MAX_TABLE;

    while (tb[h].key[0] != 0 && cnt--)
    {
        if (strcmp(tb[h].key, key) == 0)
        {
            strcpy(data, tb[h].data);
            return 1;
        }
        h = (h + 1) % MAX_TABLE;
    }
    return 0;
}

int add(const char* key, char* data)
{
    unsigned long h = hashfunction(key);

    while (tb[h].key[0] != 0)
    {
        if (strcmp(tb[h].key, key) == 0)
        {
            return 0;
        }

        h = (h + 1) % MAX_TABLE;
    }
    strcpy(tb[h].key, key);
    strcpy(tb[h].data, data);
    return 1;
}


int main_hash(int argc, char* argv[])
{
    int T, N, Q;

    cout << "Enter Test Case T : ";
    cin>>T;

    for (int test_case = 1; test_case <= T; test_case++)
    {
        memset(tb, 0, sizeof(tb));
        cout << "Enter N (Number of key , data pair) : ";
        cin >> N;
        char k[MAX_KEY + 1];
        char d[MAX_DATA + 1];

        for (int i = 0; i < N; i++)
        {
            cout << "Enter k (key) : ";
            cin >> k;
            cout << "Enter d (data) : ";
            cin >> d;
            add(k, d);
        }

        cout << "# " << test_case;

        cout << "Enter Q (Test Amount that you want to enter the key : ";
        cin >> Q;
        for (int i = 0; i < Q; i++)
        {
            char k[MAX_KEY + 1];
            char d[MAX_DATA + 1];

            cout << "Enter k : ";
            cin >> k;

            if (find(k, d))
            {
                cout << d << endl;
            }
            else
            {
                cout << "not find \n";
            }
        }
    }
	return 0;
}