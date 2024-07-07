#define _CRT_SECURE_NO_WARNINGS //freopen error 때문에 사용
#include <iostream>
#include<ctime>
using namespace std;
#define MAX_V 100001

//210514

// 동적 계획법(Dynamic programming)은 복잡한 문제를 풀기위해서 간단한 여러 개의 하위 문제로 나누어 푼 다음, 그것을 결합하여 목적에 도달하는 방법이다

// 상근이의 여동생 상냥이는 문방구에서 스티커 2n개를 구매했다.
// 스티커는 그림(a)와 같이 2행 n열로 배치되어 있다.
// 상냥이는 스티커를 이용해 책상을 꾸미려고 한다.
// 상냥이가 구매한 스티커의 품질은 매우 좋지 않다.
// 스티커 한 장을 떼면, 그 스티커와 변을 공유하는 스티커는 모두 찢어져서 사용할 수 없게 된다.
// 즉, 뗀 스티커의 왼쪽, 오른쪽, 위, 아래에 있는 스티커는 사용할 수 없게 된다.

// [백준/9465번] 스티커 (DP)
// 모든 스티커를 붙일 수 없게된 상냥이는 각 스티커에 점수를 매기고, 점수의 합이 최대가 되게 스티커를 떼어내려고 한다.
// 먼저, 그림(b)와 같이 각 스티커에 점수를 매겼다.상냥이가 뗄 수 있는 스티커의 점수의 최댓값을 구하는 프로그램을 작성하시오.
// 즉, 2n개의 스티커 중에서 점수의 합이 최대가 되면서 서로 변을 공유 하지 않는 스티커 집합을 구해야 한다.
// 위의 그림의 경우에 점수가 50, 50, 100, 60인 스티커를 고르면, 점수는 260이 되고 이 것이 최대 점수이다.
// 가장 높은 점수를 가지는 두 스티커(100과 70)은 변을 공유하기 때문에, 동시에 뗄 수 없다.

// 입력
// 2
// 5
// 50 10 100 20 40
// 30 50 70 10 60
// 7
// 10 30 10 50 100 20 40
// 20 40 30 50 60 20 80

// 출력
// #1 260
// #2 290

int N;
int dp[2][MAX_V];
int board[2][MAX_V];

const int max(const int a, const int b)
{
    return (a < b) ? b : a;
}

void findSticker()
{
    dp[0][0] = board[0][0];
    dp[1][0] = board[1][0];
    dp[0][1] = dp[1][0] + board[0][1];
    dp[1][1] = dp[0][0] + board[1][1];

    for (int i = 2; i < N; i++)
    {
        //dp[0][i] = max(dp[0][i - 2], dp[1][i - 2]);
        //dp[0][i] = max(dp[1][i - 1], dp[0][i]);
        dp[0][i] = max(dp[1][i - 1], dp[1][i - 2]);
        dp[0][i] += board[0][i];

        //dp[1][i] = max(dp[0][i - 2], dp[1][i - 2]);
        //dp[1][i] = max(dp[0][i - 1], dp[1][i]);
        dp[1][i] = max(dp[0][i - 1], dp[0][i - 2]);
        dp[1][i] += board[1][i];
    }
}

int main_dp_sticker()
{
    int T, tc;
    freopen("10_DP_sticker.txt", "r", stdin);
    cin >> T;

    for (tc = 1; tc <= T; ++tc)
    {
        cin >> N;
        //cout << "Enter N (Total Sticker number is 2N) : "<<N<<endl;

        for (int j = 0; j < 2; j++)
        {
            for (int i = 0; i < N; i++)
            {
                cin >> board[j][i];
            }
        }

        findSticker();

        //debugging
        for (int j = 0; j < 2; j++)
        {
            for (int i = 0; i < N; i++)
            {
                cout << dp[j][i] << " ";
            }
            cout << endl;
        }
        cout << endl;

        cout << "#" << tc<<" : ";
        cout << max(dp[0][N - 1], dp[1][N - 1]) << "\n";
    }

    return 0;
}