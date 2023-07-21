#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<int> longestCommonSubsequence(vector<int> a, vector<int> b)
    {
        vector<vector<int>> dp(a.size() + 1, vector<int>(b.size() + 1, 0));

        for (int i = 1; i < a.size() + 1; i++)
        {
            for (int j = 1; j < b.size() + 1; j++)
            {
                if (a[i - 1] == b[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];

                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }

        // backtracking
        int i = a.size(), j = b.size(), k = dp[i][j];

        cout << "len:" << k << endl;

        vector<int> result(k);

        while (i >= 0 && j >= 0)
        {
            cout << "i:" << i << " j:" << j << " k:" << k << endl;

            if (a[i - 1] == b[j - 1])
            {
                result[--k] = a[i - 1];
                i--;
                j--;
            }

            else if (dp[i][j] == dp[i - 1][j])
                i--;

            else
                j--;

            // cout << "result [" << k << "]:" << result[k] << endl;
        }

        return result;
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

    vector<int> a{1, 2, 3, 4, 1}, b{3, 4, 1, 2, 1, 3};

    print_vector<int>(s.longestCommonSubsequence(a, b));

    return 0;
}