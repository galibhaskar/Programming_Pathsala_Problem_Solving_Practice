#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool isExists(vector<int> &arr, int sum, int index, vector<vector<int>> &dp)
    {
        // cout << "index:" << index << " sum:" << sum << endl;

        // TC
        if (sum == 0)
            return 1;

        if (sum < 0 || index < 0)
            return 0;

        // memo check
        if (dp[index][sum] != -1)
            return dp[index][sum];

        // solve and store
        if (isExists(arr, sum, index - 1, dp) ||
            isExists(arr, sum - arr[index], index - 1, dp))
            dp[index][sum] = 1;

        else
            dp[index][sum] = 0;

        return dp[index][sum];
    }

    bool isSubsetSum(vector<int> arr, int sum)
    {
        vector<vector<int>> dp(arr.size(), vector<int>(sum + 1, -1));

        return isExists(arr, sum, arr.size() - 1, dp);
    }
};

int main(int argc, char const *argv[])
{
    Solution s;

    vector<int> arr{3, 34, 4, 12, 5, 2};

    int N = 9;

    cout << s.isSubsetSum(arr, N);

    return 0;
}