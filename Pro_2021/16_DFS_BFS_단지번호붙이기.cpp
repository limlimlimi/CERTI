#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
//#include<stdio.h> //cin�� ���� ������ �������� �Է¹޾Ƽ� scanf�� ������ �ʿ��� �� �˾Ҵµ� �ǳ�
#include <iomanip> //setw(3) �������� ���
using namespace std;

#define MAX_N 26
int N_vil;
int map[MAX_N][MAX_N];
int dp[MAX_N][MAX_N];
int vil_num[MAX_N];
int vil_cnt;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

// ������ ������ ã�� 1������ ���� ��ȣ �ο� & ���� ����
// �� ������ ���
// �� ������ ���ϴ� ���� ���� ������������ �����Ͽ� ���

////�Է�
//7
//0110100
//0110101
//1110101
//0000111
//0100000
//0111110
//0111000
////���
//3 //�Ѵ�����
//7 // �� ������ ���� ���� ������������ ���
//8
//9

void findvillage(int y, int x)
{
	//dp�ʱⰪ�� 0�̾ƴ� -1�̾�߸� dp���� �湮���θ� ��Ÿ���鼭 ���ÿ� ���� ��ȣ ��
	if (dp[y][x] >= 0) //�湮���� ������ 
		return;
	//else if (map[y][x] == 0) //�湮���� �����鼭 map==0�ϰ�� ���� �湮�� �ʿ����
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
	freopen("16_DFS_BFS_������ȣ���̱�.txt","r",stdin);
	cin >> N_vil;
	for (int y = 1; y <= N_vil; y++)
	{
		for (int x = 1; x <= N_vil; x++)
		{
			//cin >> map[y][x]; //���Ⱑ ��� �������θ� �Է� ����
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