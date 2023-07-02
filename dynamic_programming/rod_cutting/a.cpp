#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int cut_rod(int n, vector<int> &prices, vector<int> &dp)
    {
        // base case
        if (n <= 0)
            return 0;

        // memo check
        if (dp[n] != -1)
            return dp[n];

        // solve and store
        for (int j = 1; j <= n; j++)
            dp[n] = max(dp[n], prices[j - 1] + cut_rod(n - j, prices, dp));

        return dp[n];
    }

    int bottom_top_cut_rod(int rod_length, vector<int> &prices, vector<int> &dp)
    {
        dp[0] = 0;

        for (int i = 1; i <= rod_length; i++)
        {
            for (int j = 1; j <= i; j++)
                dp[i] = max(dp[i], prices[j - 1] + dp[i - j]);
        }

        return dp[rod_length];
    }
};

template <typename T>
void print_vector(vector<T> arr)
{
    cout << "-------vector begin-----" << endl;

    for (auto ele : arr)
        cout << ele << " ";

    cout << "-------vector end-----" << endl;
}

int main(int argc, char const *argv[])
{
    Solution s;
    int n;
    cin >> n;

    vector<int> prices{2, 5, 9, 9, 10, 10, 11};

    vector<int> dp(n + 1, -1);

    // cout << s.cut_rod(n, prices, dp);

    cout << s.bottom_top_cut_rod(n, prices, dp);

    return 0;
}