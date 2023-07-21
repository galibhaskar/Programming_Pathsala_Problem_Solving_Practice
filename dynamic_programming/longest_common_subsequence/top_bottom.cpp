#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int LCS(string &s1, string &s2, int s1_index, int s2_index, vector<vector<int>> &dp)
    {
        // terminating condition
        if (s1_index < 0 || s2_index < 0)
            return 0;

        // memo check
        if (dp[s1_index][s2_index] != -1)
            return dp[s1_index][s2_index];

        // solve and store
        if (s1[s1_index] == s2[s2_index])
            dp[s1_index][s2_index] = 1 + LCS(s1, s2, s1_index - 1, s2_index - 1, dp);

        else
            dp[s1_index][s2_index] = max(LCS(s1, s2, s1_index - 1, s2_index, dp),
                                         LCS(s1, s2, s1_index, s2_index - 1, dp));

        return dp[s1_index][s2_index];
    }

    int length_of_longest_common_subsequence(string s1, string s2)
    {
        vector<vector<int>> dp(s1.length(), vector<int>(s2.length(), -1));

        return LCS(s1, s2, s1.length() - 1, s2.length() - 1, dp);
    }
};

int main(int argc, char const *argv[])
{
    Solution s;

    string s1, s2;

    cin >> s1 >> s2;

    cout << s.length_of_longest_common_subsequence(s1, s2);

    return 0;
}