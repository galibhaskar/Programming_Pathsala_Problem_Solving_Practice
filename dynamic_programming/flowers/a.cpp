#include <bits/stdc++.h>
#define mod 1000000007

using namespace std;

class Solution
{
public:
    long long int count_flowers(long long int n, vector<long long int> &dp)
    {
        cout << n << endl;

        // base case
        if (n < 0)
            return 0;

        if (n == 0)
            return 1;

        // memo check
        if (dp[n] != -1)
            return dp[n] % mod;

        dp[n] = (count_flowers(n - 1, dp) % mod + count_flowers(n - 2, dp) % mod) % mod;

        return dp[n] % mod;
    }

    void solve(long long int test_cases, long long int k)
    {
        vector<long long int> dp(100001, -1);

        long long int start, end, sum = 0;

        while (test_cases--)
        {
            cin >> start >> end;

            sum = 0;

            cout << "value:" << end << " " << dp[end] << endl;

            if (dp[end] == -1)
                count_flowers(end, dp);

            for (long long int i = start; i <= end; i++)
            {
                cout << "value:" << i << " " << dp[i] << endl;

                sum = ((sum % mod) + (dp[i] % mod)) % mod;
            }

            cout << sum << endl;
        }
    }
};

int main(int argc, char const *argv[])
{
    Solution s;

    int test_cases, k;

    cin >> test_cases >> k;

    s.solve(test_cases, k);

    return 0;
}