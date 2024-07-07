#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue> //queue header file
#define MAX_NUM 100

using namespace std;

int main_queue_stl() {

	queue<int> q1;
	//q1.push(value) FIFO ��� �ֱ�
	//q1.pop() FIFO ��� ����
	//q1.front() �ֻ��� ��� ����
	//q1.back() ������ ��� ����
	//q1.size() ũ�� Ȯ��
	//q1.empty() ����ִ��� Ȯ��
	//q1.swap(queue1,queue2) �� ť�� ���� �ٲ� ��

	int T, N;
	freopen("2_Queue.txt", "r", stdin);
	//freopen("0_output.txt", "w", stdout);
	cin >> T;
	
	for (int tc = 1; tc <= T; tc++ ) {
		cin >> N;

		for (int i = 0; i < N; i++ ) {
			int value;
			cin >> value;
			q1.push(value);
		}

		cout << "#" << tc;

		while(!q1.empty()) {
			int value = q1.front();
			cout<< " " << value;
			q1.pop();
		}
		cout << endl;
	}
	

	return 0;
}