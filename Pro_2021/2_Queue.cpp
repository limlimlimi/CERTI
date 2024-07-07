#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#define MAX_NUM 100
using namespace std;

// 210425
// Queue : FIFO

// 1. void queueInit()
// 2. int queueIsEmpty()
// 3. int queueIsFull()
// 4. int queueEnqueue(int value) : stackPush(value)
// 5. int queueDequeue(int* value) : stackPop(&value)

// 1. Test Case 수 입력받기
// 2. TC_n Data 크기 입력받기 (2<=N<=100)
// 3. TC_n Data 입력하기
// 4. 출력

//const int MAX_NUM = 100;
int queue[MAX_NUM];
int front;
int rear;

void queueInit()
{
	front = 0;
	rear = 0;
}

int queueIsEmpty()
{
	return(front == rear);
}

int queueIsFull()
{
	if ((rear + 1) % MAX_NUM == front)
		return 1;
	else
		return 0;
}

int queueEnqueue(int value) //: stackPush(value)
{
	if (queueIsFull())
	{
		cout << "Queue is full";
		return 0;
	}
	queue[rear] = value;
	rear++;
	if (rear == MAX_NUM)
		rear = 0;
	return 1;
}

int queueDequeue(int* value) //: stackPop(&value)
{
	if (queueIsEmpty())
	{
		cout << "Queue is empty!";
		return 0;
	}
	*value = queue[front];
	front++;
	if (front == MAX_NUM)
		front = 0;
	return 1;
}

int main_queue()
{
	int T, N;

	freopen("2_Queue.txt", "r", stdin);
	//freopen("2_output.txt", "w", stdout);
	//cout << "Enter T (Number of Test case) : ";
	cin >> T;
	for (int TC =1 ; TC <= T ; TC++)
	{
		//cout << "Enter N (Number of data) : ";
		cin >> N;

		queueInit();
		
		for (int i = 0; i < N; i++)
		{
			int value;
			//cout << "Enter value : ";
			cin >> value;
			queueEnqueue(value);
			//cout << "SetValue \n";
		}
		cout << "#" << TC << " : ";

		while (!queueIsEmpty())
		{
			int value;
			if (queueDequeue(&value) == 1)
				cout << value<<" ";
		}
		cout << "\n";
	}
	return 0;
}