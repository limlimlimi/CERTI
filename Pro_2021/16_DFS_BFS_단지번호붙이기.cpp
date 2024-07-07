#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
//#include<stdio.h> //cin은 띄어쓰기 없으면 열단위로 입력받아서 scanf로 쓰려면 필요할 줄 알았는데 되네
#include <iomanip> //setw(3) 쓰기위해 사용
using namespace std;

#define MAX_N 26
int N_vil;
int map[MAX_N][MAX_N];
int dp[MAX_N][MAX_N];
int vil_num[MAX_N];
int vil_cnt;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

// 인접한 단지를 찾아 1번부터 단지 번호 부여 & 갯수 저장
// 총 단지수 출력
// 각 단지에 속하는 집의 수를 오름차순으로 정렬하여 출력

////입력
//7
//0110100
//0110101
//1110101
//0000111
//0100000
//0111110
//0111000
////출력
//3 //총단지수
//7 // 각 단지내 집의 수를 오름차순으로 출력
//8
//9

void findvillage(int y, int x)
{
	//dp초기값이 0이아닌 -1이어야만 dp값이 방문여부를 나타내면서 동시에 마을 번호 됨
	if (dp[y][x] >= 0) //방문한적 있으면 
		return;
	//else if (map[y][x] == 0) //방문한적 없으면서 map==0일경우 굳이 방문할 필요없음
	//	dp[y][x] = 0;
	for (int k = 0; k < 4; k++) 
	{
		dp[y][x] = vil_cnt;
		int newx = x + dx[k];
		int newy = y + dy[k];
		if (map[newy][newx] == 1 && dp[newy][newx] == -1 && newx > 0 && newy > 0 && newx <= N_vil && newy <= N_vil)
		{
			vil_num[vil_cnt] ++;
			findvillage(newy, newx);
		}
	}
}

int main_village()
{
	freopen("16_DFS_BFS_단지번호붙이기.txt","r",stdin);
	cin >> N_vil;
	for (int y = 1; y <= N_vil; y++)
	{
		for (int x = 1; x <= N_vil; x++)
		{
			//cin >> map[y][x]; //띄어쓰기가 없어서 열단위로만 입력 받음
			scanf("%1d", &map[y][x]);
			dp[y][x] = -1;
		}
	}

	vil_cnt = 0;
	for (int y = 1; y <= N_vil; y++)
	{
		for (int x = 1; x <= N_vil; x++)
		{
			if (map[y][x] == 1 && dp[y][x] == -1 )
			{
				vil_cnt++;
				vil_num[vil_cnt] ++;
				//cout << "vil_cnt=" <<vil_cnt << " & call findvillage in Main" << endl;
				findvillage(y, x);
			}
		}
	}
	cout << endl;

	//debugging-start
	cout << "map array(meanning : input data)" << endl;
	for (int y = 1; y <= N_vil; y++)
	{
		for (int x = 1; x <= N_vil; x++)
		{
			cout << setw(3) << map[y][x] << " ";
		}
		cout << endl;
	}
	cout << endl;

	cout << "dp array(meaing : visited & village no.)" << endl;
	for (int y = 1; y <= N_vil; y++)
	{
		for (int x = 1; x <= N_vil; x++)
		{
			cout <<setw(3)<< dp[y][x] << " ";
		}
		cout << endl;
	}
	cout << endl;
	//debugging-end

	cout << "Total number of village is : " << vil_cnt<<endl;
	for (int i = 1; i <= vil_cnt; i++)
	{
		cout << vil_num[i] << " ";
	}

	return 0;
}