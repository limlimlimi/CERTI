#pragma warning(suppress : 4996) //freopen error 때문에 썼는데 효과없음
#define _CRT_SECURE_NO_WARNINGS //freopen error 때문에 썼는데 효과있음
#include <iostream>
using namespace std;

#define MAX_STRING_LENGTH 10

int stackTop = 0;
char combinationStack[MAX_STRING_LENGTH];

void swap(char* x, char* y)
{
	char temp;
	temp = *x;
	*x = *y;
	*y = temp;
}

void permutation(char* str, int l, int r) //배열 , 시작인덱스, 끝인덱스
{
	if (l == r)
	{
		cout << str <<endl;
	}
	else
	{
		for (int i = l; i <= r; i++)
		{
			swap((str + l), (str + i));
			//cout << "//swap " << "[ " << l <<" ]" << " & " << "[ " << r << " ]" << " : ";
			//cout << str << endl;

			permutation(str, l + 1, r);

			swap((str + l), (str + i)); //backtrack
			//cout << "//swap " << "[ " << l << " ]" << " & " << "[ " << r << " ]" << " : ";
			//cout << str << endl;
		}
	}
}

void push(char ch)
{
	combinationStack[stackTop++] = ch;
	combinationStack[stackTop] = '\0';
}

void pop()
{
	combinationStack[--stackTop] = '\0';
}

void combination(const char* str, int length, int offset, int k) //length 총갯수, offset 시작인덱스, k 선택갯수
{
	if (k == 0)
	{
		cout << "CombinationStack: "<<combinationStack<<endl;
		return;
	}
	for (int i = offset; i <= length - k; ++i)
	{
		push(str[i]);
		combination(str, length, i + 1, k - 1);
		pop();
	}
}

int main_Permu_Combi()
{
	int N, K, T;
	char str[MAX_STRING_LENGTH];
	
	freopen("210522_Permu_Combi_input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	cin >> T;

	for (int test_case = 1; test_case <= T; test_case++)
	{
		cin >> str;
		cin >> N; //nPn=n!/(n-n)!=n!
		cin >> K; //nCk=n!/((n-k)!*k!)
		str[N] = 0;

		cout << "#"<< test_case<<endl;

		permutation(str, 0, N - 1);
		combination(str, N, 0, K);
	}

	return 0;
}
