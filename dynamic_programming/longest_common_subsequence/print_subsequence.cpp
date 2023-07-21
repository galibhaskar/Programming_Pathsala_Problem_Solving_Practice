#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int print_subsequence_bottom_top(string s1, string s2)
    {
        vector<vector<int>> dp(s1.length() + 1, vector<int>(s2.length() + 1, -1));

        vector<vector<string>> subsequence_vector(s1.length() + 1,
                                                  vector<string>(s2.length() + 1, "."));

        // first row and first col making them as 0

        for (int i = 0; i <= s1.length(); i++)
        {
            subsequence_vector[i][0] = "";
            dp[i][0] = 0;
        }

        for (int i = 0; i <= s2.length(); i++)
        {
            subsequence_vector[0][i] = "";
            dp[0][i] = 0;
        }

        int s1_index = 1, s2_index = 1;

        for (int s1_index = 1; s1_index <= s1.length(); s1_index++)
        {
            for (int s2_index = 1; s2_index <= s2.length(); s2_index++)
            {
                if (s1[s1_index - 1] == s2[s2_index - 1])
                {
                    subsequence_vector[s1_index][s2_index] =
                        subsequence_vector[s1_index - 1][s2_index - 1] + s1[s1_index - 1];

                    dp[s1_index][s2_index] = 1 + dp[s1_index - 1][s2_index - 1];
                }
                else
                {
                    int val1 = dp[s1_index][s2_index - 1], val2 = dp[s1_index - 1][s2_index];

                    dp[s1_index][s2_index] = max(val1, val2);

                    if (dp[s1_index][s2_index] == val1)
                        subsequence_vector[s1_index][s2_index] =
                            subsequence_vector[s1_index][s2_index - 1];

                    else
                        subsequence_vector[s1_index][s2_index] =
                            subsequence_vector[s1_index - 1][s2_index];
                }

                // cout << "dp[" << s1_index
                //      << "][" << s2_index << "] :"
                //      << dp[s1_index][s2_index] << endl;

                // cout << "subsequence[" << s1_index
                //      << "][" << s2_index << "] :"
                //      << subsequence_vector[s1_index][s2_index] << endl;
            }
        }

        cout << "longest subsequence:" << subsequence_vector[s1.length()][s2.length()] << endl;

        return dp[s1.length()][s2.length()];
    }
};

int main(int argc, char const *argv[])
{
    Solution s;

    string s1, s2;

    cin >> s1 >> s2;

    cout << s.print_subsequence_bottom_top(s1, s2);

    return 0;
}