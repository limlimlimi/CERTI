#define _CRT_SECURE_NO_WARNINGS //freopen error 때문에 사용
#include<iostream>
using namespace std;

#define MAX_N 1000000 //(1<=N<=1,000,000)
#define MAX_M 2000000000 //(1<=M<=2,000,000,000) 
//const int MAX_N = 1000000; //(1 <= N <= 1, 000, 000)
//const int MAX_M = 2000000000; //(1 <= M <= 2, 000, 000, 000)
// (signed) int는 -20억 ~ +20억(2*10^9)까지 감당 가능 
// (signed) long long 은 -(9*10^18) ~ +(9*10^18)까지 감당 가능

// //입력
// 4 7
// 20 15 10 17
// //출력
// 15

int main_bs_tree()
{
	int N; // 나무의 갯수
	int M; // 필요한 (집에 가져가고자 하는) 잘라낸 나무의 총 합
	int tree[MAX_N];

	cin >> N >> M;
	for (int i = 0; i < N; i++)
		cin >> tree[i];

	int low = 0;
	int high = MAX_M; // 전기톱 설정 높이 H = low이면 무조건 가능, H = high 이면 무조건 불가능

	while (low < high) // 풀이에서는 low+1 < high로 체크하던데...
	{
		int mid = (low + high) / 2; // 전기톱에 설정할 높이 H를 mid 로 잡고 범위를 찾아 나갈 것
		long long sum = 0;
		for (int i = 0; i < N; i++)
			if(tree[i]>mid)
				sum += tree[i]-mid;
		if (sum >= M)
			low = mid;
		else
			high = mid;
	}
	cout << "전기톱 설정 높이 H 의 최댓값은 ( 나무를 과하게 자르지 않고 필요한 만큼만 가져갈 수 있는 전기톱 설정 높이 ) : " << low;

	return 0;
}