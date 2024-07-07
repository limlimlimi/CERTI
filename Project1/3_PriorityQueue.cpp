#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#define MAX_NUM 100
using namespace std;

// 210430
// 작은 숫자가 높은 우선순위를 갖는 Priority Queue에 저장하고,
// 우선 순위가 높은 숫자부터 차례대로 출력하시오.

// int heapSize;
// int heap[(MAX_NUM+1)];

int heap[MAX_NUM+1];
int heapSize = 0;

void heapInit()
{
	heapSize = 1;
}

int heapPush(int value)
{
	if (heapSize > MAX_NUM)
	{
		cout << "Queue is full!";
		//printf("queue is full!");
		return 0;
	}
	heap[heapSize] = value;
	int current = heapSize;
	int parent = current / 2;

	//cout << "--------------------------------------------\n";
	//cout << "heapSize : " << heapSize << "\n";
	//cout << "current" << current << " & heap[current]" << heap[current] << "\n";
	//cout << "parent" << parent << " & heap[parent]" << heap[parent] << "\n";

	while (current > 1 && heap[current] < heap[parent])
	{
		//cout << "SWAP current = " << current << " & heap[current] = " << heap[current] << "\n";
		//cout << "& parent = " << parent << " & heap[parent] = " << heap[parent] << "\n";

		// swap current & parent
		int temp = heap[parent];
		heap[parent] = heap[current];
		heap[current] = temp;

		current = parent;
		parent = current / 2;
	}
	for (int i = 1; i <= heapSize; i++)
	{
		cout << "heap[" << i << "] : " << heap[i] << " ";
	}
	cout << endl;
	heapSize++;
	return 1;
}

int heapPop(int *value)
{
	if (heapSize <= 0)
	{
		return -1;
	}

	*value = heap[1];
	heapSize--;
	heap[1] = heap[heapSize];
	//cout << "Heap Size' : " << heapSize << " heap[HeapSize]= " << heap[heapSize] << endl;

	//debugging
	//cout << "--------------------------------------------\n";
	//cout << "Heap Size : " << heapSize << endl;
	//for (int i = 1; i <= heapSize; i++)
	//{
	//	cout << "heap[" << i << "] : " << heap[i] << " / ";
	//}
	//cout << endl;

	int current = 1;
	//int child = current * 2; //left_child
	int left_child = current * 2;
	int right_child = current * 2 + 1;
	//cout << "value in heapPop : "<< value << " &value in heapPop : " << &value << "\n";
	while (left_child < heapSize)
	{
		int child;
		if (right_child == heapSize)
		{
			child = current * 2; //left_child
		}
		else
		{
			child = heap[left_child] < heap[right_child] ? left_child : right_child;
		}

		if (heap[current] < heap[child])
		{
			//cout << "Break\n";
			break;
		}
		//cout << "SWAP " << current << " & " << child;

		// swap
		int temp = heap[current];
		heap[current] = heap[child];
		heap[child] = temp;

		//cout << "heap[current]=" << heap[current] << " // " << "heap[child]=" << heap[child] << "\n";

		current = child;
		left_child = current * 2;
		right_child = current * 2 + 1;
		//child = 2 * child;

		//debugging
		//cout << "--------------------------------------------\n";
		//for (int i = 1; i <= heapSize; i++)
		//{
		//	cout << "heap[" << i << "] : " << heap[i] << " / ";
		//}
		//cout << endl;
	}

	return 1;
}

//int main_Heap(int argc,char* argv[])
int main_Heap()
{
	// cout << "4/3 = " << 4 / 3 << endl; //ans=1
	// cout << "5/3 = " << 5 / 3 << endl; //ans=1

	int T, N;

	freopen("3_PriorityQueue.txt", "r", stdin);
	//freopen("2_output.txt", "w", stdout);

	//cout << "Enter T (Number of Test case) : ";
	cin >> T;
	for (int test_case = 1; test_case <= T; test_case++)
	{
		//cout << "Enter N (Number of data) : ";
		cin >> N;
		cout << "N is " << N << endl;;
		heapInit();

		for (int i = 1; i <= N; i++) 
		{
			int value;
			//cout << "Enter Data :";
			cin >> value;
			heapPush(value);
			//cout << "SetValue.\n";
		}

		cout << "--------------------------------------------\n";
		cout << "--------------------------------------------\n";
		cout << "#" << test_case << " : \n";

		for(int i=1;i<=N;i++)
		{
			int value;
			heapPop(&value);
			cout << value<<" \n";
		}
		cout << "\n";
	}
	return 0;
}