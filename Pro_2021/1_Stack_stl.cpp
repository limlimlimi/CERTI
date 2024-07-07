#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stack> //stack header file - STL(Standard Templete Library)�� �Ϻη� LIFO ������ �ڷᱸ��
#define MAX_NUM 100

using namespace std;

int main_stack_stl() {

	stack<int> stack1;
	//stack1.push(value) LIFO ��� �ֱ�
	//stack1.pop() LIFO ��� ����
	//stack1.top() �ֻ��� ��� ����
	//stack1.size() ũ�� Ȯ��
	//stack1.empty() ����ִ��� Ȯ��

	int T; // Number of Test Case
	int N; // Size of Data

	freopen("1_Stack.txt", "r", stdin);
	//freopen("0_output.txt", "w", stdout);
	cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		cin >> N;
		for (int j = 0; j < N; j++) {
			int value;
			cin >> value;
			stack1.push(value);
		}

		cout << "#" << tc;
		while(!stack1.empty()){
			int value;
			value = stack1.top();
			cout << " " << value;
			stack1.pop();
		}
		cout << endl;
	}
	return 0;
}

/*
int main_stack_stl() {
	stack<int> stack1; //��üobject ����

	stack1.push(10);
	stack1.push(20);

	cout << "Top element is " << stack1.top() << endl;
	cout << "Stack Size is " << stack1.size() << endl;

	stack1.pop();
	cout << "Top element is " << stack1.top() << endl;
	cout << "Stack Size after pop is " << stack1.size() << endl;

	if (stack1.empty())
		cout << "Stack is empty" << endl;
	else
		cout << "Stack is not empty" << endl;

	return 0;
}
*/
