#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int knapSack(int W, int wt[], int val[], int n)
    {
        vector<vector<int>> dp(n + 1, vector<int>(W + 1, -1));

        // initialization
        for (int i = 0; i < n + 1; i++)
            dp[i][0] = 0;

        // extra row initialization
        for (int i = 0; i < W + 1; i++)
            dp[0][i] = 0;

        for (int i = 1; i < n + 1; i++)
        {
            for (int j = 1; j < W + 1; j++)
            {
                dp[i][j] = dp[i - 1][j];

                if (j - wt[i - 1] >= 0)
                    dp[i][j] = max(dp[i][j],
                                   val[i - 1] + dp[i - 1][j - wt[i - 1]]);
            }
        }

        return dp[n][W];
    }
};

int main(int argc, char const *argv[])
{
    Solution s;

    int wt[3] = {4, 5, 1};

    int val[3] = {1, 2, 3};

    int N = 3, W = 4;

    cout << s.knapSack(W, wt, val, N);

    return 0;
}