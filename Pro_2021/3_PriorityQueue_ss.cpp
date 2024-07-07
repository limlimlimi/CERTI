#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
using namespace std;
#define MAX_SIZE 100

int heap_[MAX_SIZE];
int heapSize_ = 0;

void heapInit_(void)
{
	heapSize_ = 0;
}

int heapPush_(int value)
{
	if (heapSize_ + 1 > MAX_SIZE)
	{
		printf("queue is full!");
		return 0;
	}

	heap_[heapSize_] = value;

	int current = heapSize_;
	while (current > 0 && heap_[current] < heap_[(current - 1) / 2])
	{
		int temp = heap_[(current - 1) / 2];
		heap_[(current - 1) / 2] = heap_[current];
		heap_[current] = temp;
		current = (current - 1) / 2;
	}

	heapSize_ = heapSize_ + 1;

	for (int i = 0; i < heapSize_; i++)
	{
		cout << "[" << i << "] : " << heap_[i] << " / ";
	}
	cout << endl;

	return 1;
}

int heapPop_(int* value)
{
    if (heapSize_ <= 0)
    {
        return -1;
    }

    *value = heap_[0];
    heapSize_ = heapSize_ - 1;

    heap_[0] = heap_[heapSize_];

    int current = 0;
    while (current * 2 + 1 < heapSize_)
    {
        int child;
        if (current * 2 + 2 == heapSize_)
        {
            child = current * 2 + 1;
        }
        else
        {
            child = heap_[current * 2 + 1] < heap_[current * 2 + 2] ? current * 2 + 1 : current * 2 + 2;
        }

        if (heap_[current] < heap_[child])
        {
            break;
        }

        int temp = heap_[current];
        heap_[current] = heap_[child];
        heap_[child] = temp;

        current = child;
    }
    return 1;
}

//int main_Heap(int argc, char* argv[])
int main_Heap_ss()
{
    int T, N;

    freopen("3_PriorityQueue.txt", "r", stdin);
    cin >> T;

    for (int tc = 1; tc <= T; tc++)
    {
        cin >> N;
        //cout << "N is " << N << endl;;

        heapInit_();

        for (int i = 0; i < N; i++)
        {
            int value;
            cin >> value;
            heapPush_(value);
        }

        cout << "--------------------------------------------\n";
        cout << "--------------------------------------------\n";
        cout << "#" << tc << " : ";

        for (int i = 0; i < N; i++)
        {
            int value;
            heapPop_(&value);
            cout << value << " ";
        }
        cout << "\n";
    }
    return 0;
}