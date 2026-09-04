#include <bits/stdc++.h>
using namespace std;

// In this lectre we are going to solve KANPSCK prblems
// 0-1 Knapsack

// in kapsack problems we rae given a item with their weight and val and capacity of knapsack
// the problem is to select the items that could maximize the val while satisfying the knapsack capacity

// Recursive solution
int Knapsack(vector<int> &v, vector<int> &weight, int W, int n)
{
    // whenevr our knapsack gets full or n becomes less than zero we will simply return
    if (n <= 0 || W <= 0)
        return 0;

    // include curent item
    int val = v[n - 1];
    int wt = weight[n - 1];

    // if wt is less than or eqal to capacity of knapsack
    if (wt <= W)
    {

        // we have two choices

        // include the current item
        int ans1 = Knapsack(v, weight, W - wt, n - 1) + v[n - 1];

        // exclude current item
        int ans2 = Knapsack(v, weight, W, n - 1);
        return max(ans1, ans2);
    }
    else
    {
        return Knapsack(v, weight, W, n - 1);
    }
}

// Memoized solution

int KnapsackMemo(vector<vector<int>> &dp, vector<int> &profit, vector<int> &weight, int W, int n)
{
    if (n <= 0 || W <= 0)
        return 0;

    if (dp[n][W] != -1)
        return dp[n][W];
    int wt = weight[n - 1];
    int prof = profit[n - 1];

    if (wt <= W)
    {
        int ans1 = KnapsackMemo(dp, profit, weight, W - wt, n - 1) + prof;
        int ans2 = KnapsackMemo(dp, profit, weight, W, n - 1);

        dp[n][W] = max(ans1, ans2);
    }
    else
    {
        return KnapsackMemo(dp, profit, weight, W, n - 1);
    }
    return dp[n][W];
}

// tabulation

int main()
{

    vector<int> val = {1, 2, 3};
    vector<int> weight = {4, 5, 1};
    int W = 4;

    vector<vector<int>> dp(val.size() + 1, vector<int>(W + 1, -1));
    cout << "Recursive solution " << Knapsack(val, weight, W, val.size()) << endl;
    cout << "Memoized " << KnapsackMemo(dp, val, weight, W, val.size()) << endl;

    for (int i = 0; i <= val.size(); i++)
    {
        for (int j = 0; j <= W; j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
}