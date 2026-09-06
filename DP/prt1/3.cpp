#include <bits/stdc++.h>
using namespace std;

// In this lectre we are going to solve KANPSCK prblems
// 0-1 Knapsack

// in kapsack problems we rae given a item with their weight and val and capacity of knapsack
// the problem is to select the items that could maximize the val while satisfying the knapsack capacity

// Recursive solution
int Knapsack(vector<int> &v, vector<int> &weight, int W, int n)
{
    if (n <= 0 || W <= 0)
        return 0;

    int val = v[n - 1];
    int wt = weight[n - 1];

    if (wt <= W)
    {
        int ans1 = Knapsack(v, weight, W - wt, n - 1) + v[n - 1];
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
int KnapsackTab(int n, int W, vector<int> &profit, vector<int> &weight)
{
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= W; j++)
        {
            int itemWeight = weight[i - 1];
            int itemProfit = profit[i - 1];

            if (itemWeight <= j)
            {
                dp[i][j] = max(dp[i - 1][j],
                               dp[i - 1][j - itemWeight] + itemProfit);
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    vector<bool> selected(n, false);
    int i = n;
    int j = W;

    while (i > 0 && j > 0)
    {
        if (dp[i][j] != dp[i - 1][j])
        {
            selected[i - 1] = true;
            j -= weight[i - 1];
        }
        i--;
    }

    cout << "Included items: ";
    bool anyIncluded = false;
    for (int k = 0; k < n; k++)
    {
        if (selected[k])
        {
            cout << k + 1 << " ";
            anyIncluded = true;
        }
    }
    if (!anyIncluded) cout << "None";
    cout << endl;

    cout << "Not included items: ";
    bool anyNotIncluded = false;
    for (int k = 0; k < n; k++)
    {
        if (!selected[k])
        {
            cout << k + 1 << " ";
            anyNotIncluded = true;
        }
    }
    if (!anyNotIncluded) cout << "None";
    cout << endl;

    return dp[n][W];
}

int main()
{
    vector<int> val = {60, 100, 120};
    vector<int> weight = {10, 20, 30};
    int W = 50;

    cout << "Tabulation " << KnapsackTab(val.size(), W, val, weight) << endl;
    return 0;
}
