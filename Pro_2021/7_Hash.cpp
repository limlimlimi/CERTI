#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
#include<cstdio> // C언어의 stdio.h와 같습니다. //입출력과 관련된 옛날 C함수들을 포함한 헤더파일입니다. (printf(), fprintf(), fopen, etc)
#include<memory> //같은 메모리를 조작하는 함수를 사용하기 위해 작성 : memcpy , memset , memcmp

// 210514

#define MAX_KEY 64
#define MAX_DATA 128
#define MAX_TABLE 4096

using namespace std;

//close Addressing 방식의 chaining기법 이용한 해시 테이블 구현
//Hash table은 키를 값에 매핑할 수 있는 구조인, 연관 배열 추가에 사용되는 자료 구조이다. 
//Hash table은 Hash 함수를 사용하여 색인(index, Key)을 버킷(bucket)이나 슬롯(slot)의 배열로 계산한다.

//주어진 N개의 key, data쌍을 Hash table에 입력한 후, 
//Q개의 key를 입력 받아 key에 해당하는 data를 각 줄에 출력하시오. (1 <= N, Q <= 4096)
//* Key : 최대 64개의 문자열
//* Data : 최대 128개의 문자열

//입력 (key)
//123123
//123
//23
//4
//serf

//출력 (data)
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