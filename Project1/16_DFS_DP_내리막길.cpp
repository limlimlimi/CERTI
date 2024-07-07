#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip> //setw(3) 쓰기위해 사용
using namespace std;

//입력
//4 5
//50 45 37 32 30
//35 50 40 20 25
//30 30 25 17 28
//27 24 22 15 10
//출력
//3

//좌우상하 4방면으로 탐색
int dx1[4] = { 1, 0, -1, 0 };
int dy1[4] = { 0, 1, 0, -1 };
int arr1[501][501];
int dp1[501][501];
int n1, m1;

int dfs(int y, int x) {
    int k;

    if (y == m1 && x == n1) {
        return 1;
    }
    else if (dp1[y][x] == -1) {
        dp1[y][x] = 0;
        for (k = 0; k < 4; k++) {
            int newy = y + dy1[k];
            int newx = x + dx1[k];
            if (newx > 0 && newx <= n1 && newy > 0 && newy <= m1 && arr1[y][x] > arr1[newy][newx]) {
                //debugging start
                cout<< "dp1[" << y << "][" << x << "] += dfs(" << newy << ", " << newx <<")"<<endl;
                //debugging end
                dp1[y][x] += dfs(newy, newx);
            }
        }
    }
    //debugging start
    for (int y = 1; y <= m1; y++) {
        for (int x = 1; x <= n1; x++) {
            cout << setw(3) << dp1[y][x] << " ";
        }
        cout << endl;
    }
    cout << endl;
    //debugging end

    return dp1[y][x];
}

int main_underpath()
{
    freopen("16_DFS_DP_내리막길.txt","r",stdin);
    cin >> m1 >> n1;
    int i, j;

    for (i = 0; i <= m1; i++) {
        for (j = 0; j <= n1; j++) {
            dp1[i][j] = -1;
            arr1[i][j] = 10001;
        }
    }

    for (i = 1; i <= m1; i++) {
        for (j = 1; j <= n1; j++) {
            cin >> arr1[i][j];
        }
    }

    cout << dfs(1, 1)<<endl;

    return 0;
}