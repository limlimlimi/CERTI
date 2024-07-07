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

int input_qs[MAX_NUM];
int num_qs;

void quickSort(int first, int last)
{
    int pivot, i, j, temp;

    if (first < last)
    {
        pivot = first;
        i = first;
        j = last;

        while (i < j)
        {
            while (input_qs[i] <= input_qs[pivot] && i < last)
            {
                i++;
            }
            while (input_qs[j] > input_qs[pivot])
            {
                j--;
            }
            if (i < j)
            {
                temp = input_qs[i];
                input_qs[i] = input_qs[j];
                input_qs[j] = temp;
            }
        }

        temp = input_qs[pivot];
        input_qs[pivot] = input_qs[j];
        input_qs[j] = temp;

        quickSort(first, j - 1);
        quickSort(j + 1, last);
    }
}

void print_QS_Result(void)
{
    int i;

    for (i = 0; i < num_qs; ++i)
    {
        cout << input_qs[i];
    }
    cout << endl;
}

int main_quick_sort()
{
    int T, tc;

    freopen("11_QuickSort.txt", "r", stdin);
    cin >> T;

    for (tc = 1; tc <= T; tc++)
    {
        cin >> num_qs;

        for (int i = 0; i < num_qs; i++)
        {
            cin >> input_qs[i];
        }
        quickSort(0, num_qs - 1);
        cout << "# " << tc << " : ";
        print_QS_Result();
    }

    return 0;
}