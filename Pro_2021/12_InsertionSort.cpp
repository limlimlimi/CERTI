#define _CRT_SECURE_NO_WARNINGS //freopen error 때문에 사용
#include<iostream>
using namespace std;

// 210515_Insertion_Sort.cpp & 210515_Quick_Sort.cpp make crash, so need to comment out each code before run
////입력
//1 // 전체 Test case 수
//5 // 데이터 크기
//1 4 5 2 3
////출력
//#1 1 2 3 4 5

#define MAX_NUM 100

int input_is[MAX_NUM];
int num_is;

void insertionSort(void)
{
    for (int i = 1; i < num_is; i++)
    {
        int temp = input_is[i];
        int j = i - 1;

        while ((j >= 0) && (temp < input_is[j]))
        {
            input_is[j + 1] = input_is[j];
            j = j - 1;
        }
        input_is[j + 1] = temp;
    }
}

void print_IS_Result(void)
{
    for (int i = 0; i < num_is; ++i)
    {
        cout<<input_is[i];
    }
    cout << endl;
}

int main_insert_sort()
{
    int T, tc;

    freopen("12_InsertionSort.txt","r",stdin);
    cin >> T;

    for (tc = 1; tc <= T; tc++)
    {
        cin >>num_is;
        for (int i = 0; i < num_is; i++)
        {
            cin >> input_is[i];
        }
        insertionSort();
        cout << "# " << tc << " : ";
        print_IS_Result();
    }

    return 0;
}