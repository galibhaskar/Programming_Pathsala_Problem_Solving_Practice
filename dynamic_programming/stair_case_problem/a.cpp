#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int minCostToTop(int i, int N, vector<int> &cost, vector<int> &dp)
    {
        // terminating conditions
        if (i > N)
            return 0;

        // memo check
        if (dp[i] != -1)
            return dp[i];

        // solve and store
        dp[i] = cost[i] + min(minCostToTop(i + 1, N, cost, dp), minCostToTop(i + 2, N, cost, dp));

        cout << "i:" << i << " - " << dp[i] << endl;

        return dp[i];
    }

    int bottom_top(int start, int N, vector<int> &cost)
    {
        // cout << "start:" << start << endl;

        // function -> min cost from step 0 to i
        int f = cost[start], s = cost[start + 1] + f, curr;

        for (int i = start + 2; i < N; i++)
        {
            // cout << "f:" << f << " s:" << s << endl;

            curr = cost[i] + min(f, s);

            f = s;

            s = curr;
        }

        // cout << "s:" << s << endl;

        return min(f, s);
    }

    int minCostClimbingStairs(vector<int> &cost)
    {
        if (cost.size() == 1)
            return cost[0];

        if (cost.size() == 2)
            return min(cost[0], cost[1]);

        return min(bottom_top(0, cost.size(), cost),
                   bottom_top(1, cost.size(), cost));

        // vector<int> dp(cost.size() + 1, -1);
        // return min(minCostToTop(0, cost.size() - 1, cost, dp),
        //            minCostToTop(1, cost.size() - 1, cost, dp));
    }
};

int main(int argc, char const *argv[])
{
    Solution s;

    vector<int> c{1, 100, 1, 1, 1, 100, 1, 1, 100, 1};

    cout << s.minCostClimbingStairs(c);

    return 0;
}