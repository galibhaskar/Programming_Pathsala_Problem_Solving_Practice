#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int solve(int W, int *wt, int *val, int index, vector<vector<int>> &dp)
    {
        if (W < 0)
            return INT_MIN;

        if (index < 0)
            return 0;

        // memo check
        if (dp[index][W] != -1)
            return dp[index][W];

        // solve and store
        dp[index][W] = max(solve(W, wt, val, index - 1, dp),
                           val[index] + solve(W - wt[index], wt, val, index, dp));

        return dp[index][W];
    }

    int knapSack(int W, int wt[], int val[], int n)
    {
        vector<vector<int>> dp(n, vector<int>(W + 1, -1));

        return solve(W, wt, val, n - 1, dp);
    }
};

int main(int argc, char const *argv[])
{
    Solution s;

    int wt[3] = {4, 5, 6};

    int val[3] = {1, 2, 3};

    int N = 3, W = 3;

    cout << s.knapSack(W, wt, val, N);

    return 0;
}