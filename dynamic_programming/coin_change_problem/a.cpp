#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    long long getDeno(vector<int> &coins, int amount, vector<long long> &dp)
    {
        if (amount == 0)
            return 0;

        if (amount < 0)
            return INT_MAX;

        // memo check
        if (dp[amount] != -1)
            return dp[amount];

        // solve and store
        dp[amount] = INT_MAX;

        for (int i = 0; i < coins.size(); i++)
        {
            // handling negative denominations
            if (amount - coins[i] >= 0)
                dp[amount] = min(dp[amount], coinChange(coins, amount - coins[i]) + 1);
        }

        return dp[amount];
    }
    long long int coinChange(vector<int> &coins, int amount)
    {
        vector<long long> dp(amount + 1, -1);

        return getDeno(coins, amount, dp);
    }
};

int main(int argc, char const *argv[])
{
    Solution s;

    vector<int> deno{2, 3, 5};

    cout << s.coinChange(deno, 11);

    return 0;
}