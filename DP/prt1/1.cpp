#include <iostream>
#include <vector>
using namespace std;

// from now on we are going to study DYNAMIC PROGRAMMING
// dynammic programming is a algorithmic technique which used to solve problems
// it reduces the exponential TC funcitons into polynomial
// the term optimal substructurw used into the DP is
// a problem could be said that it follows optimal substructure means
// if the optimal solution of the problem can be built using optimal solution of its subproblems

// we will start with a lil recursion
// lets see fibnoacci sequence

// fibnoacci with recursion

int fib(int n)
{
    if (n == 0 || n == 1)
        return n;
    return fib(n - 1) + fib(n - 2);
}

// DP IS DIVIDED INTO TWO TYPES
// => MeMOIZATION TOP DOWN APPROACH
// => TABULATION BOTTOM UP APPRAOCH

int fibDP(int n, vector<int> &memo)
{
    if (memo[n] != -1)
    {
        return memo[n];
    }
    if (n == 0 || n == 1)
    {
        return memo[n];
    }
    memo[n] = fibDP(n - 1, memo) + fibDP(n - 2, memo);

    return memo[n];
}

int fibTabu(int n)
{
    vector<int> fib(n + 1, 0);

    fib[0] = 0;
    fib[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        fib[i] = fib[i - 1] + fib[i - 2];
    }

    return fib[n];
}

int main()
{

    vector<int> memo(6, -1);
    memo[0] = 0;
    memo[1] = 1;

    fibDP(5, memo);
    for (int v : memo)
    {
        cout << v << " ";
    }

    int ans = fibTabu(6);
    cout << endl;

    cout << ans << endl;

    return 0;
}