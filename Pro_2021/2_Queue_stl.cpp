#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue> //queue header file
#define MAX_NUM 100

using namespace std;

int main_queue_stl() {

	queue<int> q1;
	//q1.push(value) FIFO 방식 넣기
	//q1.pop() FIFO 방식 삭제
	//q1.front() 최상위 요소 접근
	//q1.back() 마지막 요소 접근
	//q1.size() 크기 확인
	//q1.empty() 비어있는지 확인
	//q1.swap(queue1,queue2) 두 큐의 내용 바꿀 때

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