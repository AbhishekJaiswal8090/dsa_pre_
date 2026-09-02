#include <bits/stc++.h>
using namespace std;

// In this lecture we are going to solve problems climbing stairs
// the prolems is similar to the fibonacci
// we are given that eityher we can climb 1 or 2 stair at a time
// the problem is to find out the number of ways to reach n steps
// since we can see that number of ways to reach 1 is 1 and ways to reach 2 is 2 that would become base case if using recursion

int climbingStair(int n)
{
    if (n == 1)
        return 1;
    if (n == 2)
        return 2;

    return climbingStair(n - 1) + climbingStair(n - 2);
}

// using DP
// memo

int climbingStairMemo(int n, vector<int> &memo)
{
    if (n == 1)
        return memo[1];
    if (n == 2)
        return memo[2];

    memo[n] = climbingStair(n - 1, memo) + climbingStair(n - 2, memo);
    return memo[n];
}

// Tabulation

int cimbingStairTabu(int n)
{
    vector<int> tab(n, 0);
    tab[1] = 1;
    tab[2] = 2;

    for (int i = 3; i <= n; i++)
    {
        tab[i] = tab[i - 1] + tab[i - 2];
    }

    return tab[n];
}

int main()
{
}