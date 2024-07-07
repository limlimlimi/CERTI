#define _CRT_SECURE_NO_WARNINGS //freopen error 때문에 사용
#include<iostream>
using namespace std;

#define MAX_M 100

////입력
//2 // # of test case T
//12 // # of element in array M
//5 // # of numbers to search N
//3 7 28 29 43 49 55 58 69 77 79 99 // sorted integer array
//8 49 58 44 7 // numbers to search
//7
//3
//3 4 5 6 7 8 9
//1 2 3
////출력
//#1 - 1 5 7 - 1 1
//#2 - 1 - 1 0

int arr[MAX_M];

void binarySearch(int* arr, int low, int high, int target)
{
    int mid;
    if (low > high)
    {
        cout << "-1 ";
        return;
    }

    mid = (low + high) / 2;

    if (target < arr[mid])
    {
        binarySearch(arr, low, mid - 1, target);
    }
    else if (arr[mid] < target)
    {
        binarySearch(arr, mid + 1, high, target);
    }
    else
    {
        cout << mid<<"  ";
        return;
    }
}

int main_binary_search()
{
    int T;    // # of test case
    int M;    // # of element in array
    int N;    // # of numbers to search
    int targetValue;

    freopen("13_BinarySearch.txt","r",stdin);
    cin >> T;

    for (int tc = 1; tc <= T; tc++)
    {
        cout << "# " << tc << " : ";
        //scanf("%d %d", &M, &N);
        cin >> M >> N;

        for (int i = 0; i < M; i++)
        {
            //scanf("%d", &arr[i]);
            cin >> arr[i];
        }

        for (int i = 0; i < N; i++)
        {
            //scanf("%d", &targetValue);
            cin >> targetValue;
            binarySearch(arr, 0, M - 1, targetValue);
        }
        cout << endl;
    }
    return 0;
}