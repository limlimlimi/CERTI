#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>

using namespace std;

int main_Heap_stl() {

	//priority_queue<int> pq; //Big Number have the priority.
	//priority_queue<int, vector<int>, less<int>> pq; //Big Number have the priority
	priority_queue<int, vector<int>, greater<int>> pq; //Small Number have the priority.
	
	int T, N;
	freopen("3_PriorityQueue.txt", "r",stdin);
	//freopen("0_output.txt", "w", stdout);
	
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		cin >> N;
		for (int i = 0; i < N; i++) {
			int value;
			cin >> value;
			pq.push(value);
		}

		cout << "#" << tc;

		while (!pq.empty()) {
			cout << " " << pq.top();
			pq.pop();
		}
		cout << endl;
	}
	return 0;
}