#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int distinct_denominations(vector<int> &coins, int index, int amount)
    {
        // TC
        if (amount == 0)
            return 1;

        if (amount < 0 || index < 0)
            return 0;

        // recursion
        return distinct_denominations(coins, index - 1, amount) +
               distinct_denominations(coins, index, amount - coins[index]);
    }

    int top_down_approach(vector<int> &coins, vector<vector<int>> &dp, int index, int amount)
    {
        // TC
        if (amount == 0)
            return 1;

        if (amount < 0 || index < 0)
            return 0;

        // memo check
        if (dp[index][amount] != -1)
            return dp[index][amount];

        // solve and store
        dp[index][amount] = top_down_approach(coins, dp, index - 1, amount) +
                            top_down_approach(coins, dp, index, amount - coins[index]);

        return dp[index][amount];
    }

    int bottom_top_approach(vector<int> &coins, int amount)
    {
        vector<vector<int>> dp(coins.size() + 1, vector<int>(amount + 1, -1));

        // first column of dp array -> 1
        for (int i = 0; i <= coins.size(); i++)
            dp[i][0] = 1;

        // first row  of dp array -> 0
        for (int i = 1; i <= amount; i++)
            dp[0][i] = 0;

        for (int idx = 1; idx <= coins.size(); idx++)
        {
            for (int amount_value = 1; amount_value <= amount; amount_value++)
            {
                dp[idx][amount_value] = dp[idx - 1][amount_value];

                if (amount_value - coins[idx - 1] >= 0)
                    dp[idx][amount_value] += dp[idx][amount_value - coins[idx - 1]];
            }
        }

        return dp[coins.size()][amount];
    }
};

int main(int argc, char const *argv[])
{
    Solution s;

    vector<int> coins{1, 2, 3};

    int amount = 4;

    vector<vector<int>> dp(coins.size(), vector<int>(amount + 1, -1));

    // cout << s.distinct_denominations(coins, coins.size() - 1, amount);
    // cout << s.top_down_approach(coins, dp, coins.size() - 1, amount);
    cout << s.bottom_top_approach(coins, amount);

    return 0;
}