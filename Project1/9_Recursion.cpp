#define _CRT_SECURE_NO_WARNINGS //freopen error 때문에 사용
#include <iostream>
#include<ctime>
using namespace std;

#define MAX_V 1000

int mem[MAX_V];
int tabulation[MAX_V];
long long mem_fac[MAX_V];
long long mem_tab[MAX_V];

//////////////////////////////////////////////////////////////////////////
// fibonacci
//////////////////////////////////////////////////////////////////////////
int fibo(int n) 
{ 
	if (n == 1 || n == 2) 
		return 1; 
	else 
		return fibo(n - 1) + fibo(n - 2);
}

int fibo_memoization(int n) 
{ 
    if (n == 1 || n == 2) 
        return 1; 
    else 
    { 
        if (mem[n] == 0) 
            mem[n] = fibo_memoization(n - 1) + fibo_memoization(n - 2);
        return mem[n]; 
    } 
}
int fibo_bottom_up(int n) 
{ 
    //tabulation is kind of DP, calculation from bottom 
    if (tabulation[n] == 0)
    {
        tabulation[2] = tabulation[1] = 1;
        for (int i = 3; i <= n; i++)
            tabulation[i] = tabulation[i - 1] + tabulation[i - 2];
    }
    return tabulation[n];

}

//////////////////////////////////////////////////////////////////////////
// factorial
//////////////////////////////////////////////////////////////////////////
long long factorial(int n)
{
    if (n == 0)
        return 1;
    else
        return n * factorial(n - 1);
}

long long factorial_memoization(int n)
{
    if (n == 0)
        return 1;
    else
    {
        if(mem_fac[n]==0)
            mem_fac[n]= n * factorial(n - 1);
        return mem_fac[n];
    }
}

long long factorial_tab(int n)
{
    if (mem_tab[n] == 0)
    {
        mem_tab[0] = mem_tab[1] = 1;
        for (int i = 2; i <= n; i++)
            mem_tab[n] = n * mem_tab[n - 1];
    }
    return mem_tab[n];
}

int main_recursion()
{
    // 시작 시간
    clock_t startTime = clock();

    int tc;
    int T;
    int num;
    long long value;
    int value2;

    freopen("9_Recursion.txt","r",stdin);
    cin >> T;

    for (tc = 1; tc <= T; ++tc)
    {
        cin >> num;

        //clear
        for (int i = 0; i <= num; i++)
        {
            mem[i] = 0;
            mem_fac[i] = 0;
            tabulation[i] = 0;
            mem_tab[i] = 0;
        }

        value = factorial_memoization(num);
        value2 = fibo_bottom_up(num);
        cout << "# " << tc << endl;
        cout << num << "! = " << value  << " : fibo(" << num << ") = " << value2 << endl;
        //printf("#%d %d! = %lld\n", test_case, num, value);
    }

    // 종료 시간
    clock_t endTime = clock();

    // Millisecond
    clock_t elapsed = endTime - startTime;

    // Second
    double timeInSecond = (double)(elapsed / CLOCKS_PER_SEC);

    cout << "Elapsed: " << timeInSecond << "s(" << elapsed << "ms)" << "\n";

    return 0;
}
