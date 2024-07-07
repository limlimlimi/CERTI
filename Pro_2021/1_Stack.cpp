#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#define MAX_NUM 100
using namespace std;

// 210424
// Stack : LIFO

// 1. int stackInit()
// 2. int stackIsEmpty()
// 3. int stackIsFull()
// 4. int stackPush(int value) : stackPush(value)
// 5. int stackPop(int* value) : stackPop(&value)

// 1. Test Case �� �Է¹ޱ�
// 2. TC_n Data ũ�� �Է¹ޱ� (2<=N<=100)
// 3. TC_n Data �Է��ϱ�
// 4. ���

// C : #define MAX_NUM 100;
// C++ : const int MAX_NUM = 100;

// C : scanf("%d", &n); 
// C++ : cin >> n;

int index;
int stack[MAX_NUM];

void stackInit()
{
	index = 0;
}

int stackIsEmpty()
{
	return (index == 0);
}

int stackIsFull()
{
	return (index == MAX_NUM);
}

int stackPush(int value)
{
	if (stackIsFull())
	{
		cout << "stack overflow";
		return 0;
	}
	stack[index] = value;
	index++;
	return 1;
}

int stackPop(int* value)
{
	if (stackIsEmpty())
	{
		cout << "stack is empty";
		return 0;
	}
	index--;
	*value = stack[index];
	return 1;
}

int main_stack()
{

	freopen("1_Stack.txt","r",stdin);
	//freopen("1_Stack_output.txt", "w", stdout);
	int T, N;
	//1. TestCase ���� �Է¹ޱ�
	//cout << "Enter TC : ";
	cin >> T ;
	
	for (int TC=1 ;TC<=T;TC++)
	{
		//2. Data ���� �Է¹ޱ�
		//cout << "Enter Number of Data in TC : ";
		cin >> N;

		//3. Data �Է¹ޱ�
		stackInit();
		for (int i=0; i<N; i++)
		{
			int value;
			//cout << "Enter Data : ";
			//cin >> stack[i];
			cin >> value;
			stackPush(value);
		}

		//4.���
		cout << "#" << TC << " : ";
		
		while(!stackIsEmpty())
		{
			int value;
			if(stackPop(&value)==1)
				//cout << stack[i];
				cout << value << " ";
		}
		cout << "\n" ;
	}
	return 0;
}