#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    long long int maxProfit(int start, int end, int arr[], vector<long long int> &dp)
    {
        // terminating condition
        if (start > end)
            return 0;

        // memo check
        if (dp[start] != -1)
            return dp[start];

        // solve and store
        dp[start] = max(arr[start] + maxProfit(start + 2, end, arr, dp),
                        maxProfit(start + 1, end, arr, dp));

        return dp[start];
    }

    long long int findMaxSum(int arr[], int n)
    {
        vector<long long int> dp(n, -1);

        return max(maxProfit(0, n - 1, arr, dp), maxProfit(1, n - 1, arr, dp));
    }

    int findMaxSumBottomTop(int arr[], int n)
    {
        if (n == 1)
            return arr[0];

        if (n == 2)
            return max(arr[0], arr[1]);

        int f = arr[0], s = max(arr[0], arr[1]), curr;

        for (int i = 2; i < n; i++)
        {
            curr = max(arr[i] + f, s);

            f = s;

            s = curr;
        }

        return s;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    int n;

    cin >> n;

    int arr[n];

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    // cout << s.findMaxSum(arr, n);
    cout << s.findMaxSumBottomTop(arr, n);

    return 0;
}