#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int find2dMax(int start, int end, vector<vector<int>> &mat, vector<int> &dp)
    {
        // terminating condition
        if (start > end)
            return 0;

        // memo check
        if (dp[start] != -1)
            return dp[start];

        // solve and store
        int first_value = (max(mat[0][start], mat[1][start]) + find2dMax(start + 2, end, mat, dp));

        int second_value = find2dMax(start + 1, end, mat, dp);

        dp[start] = max(first_value, second_value);

        return dp[start];
    }

    int maxSum(int N, vector<vector<int>> &mat)
    {
        vector<int> dp(N + 1, -1);

        return max(find2dMax(0, N - 1, mat, dp), find2dMax(1, N - 1, mat, dp));
    }

    int maxSumBottomTop(int N, vector<vector<int>> &mat)
    {
        int f = max(mat[0][0], mat[1][0]),
            s = max(f, max(mat[0][1], mat[1][1])), curr;

        if (N == 1)
            return f;

        if (N == 2)
            return s;

        for (int i = 2; i < N; i++)
        {
            cout << "f:" << f << " s:" << s << endl;

            curr = max(f + max(mat[0][i], mat[1][i]), s);

            f = s;

            s = curr;
        }

        return s;
    }
};

template <typename T, typename size_type>
vector<vector<T>> scan_2d_vector(size_type row_count = 0, size_type col_count = 0)
{
    size_type m, n, i = 0, j;

    if (row_count == 0 || col_count == 0)
        cin >> m >> n;

    else
    {
        m = row_count;
        n = col_count;
    }

    vector<vector<T>> arr(m, vector<T>(n));

    for (auto i = 0; i < m; i++)
        for (auto j = 0; j < n; j++)
            cin >> arr[i][j];

    return arr;
}

int main(int argc, char const *argv[])
{
    Solution s;
    int n;
    cin >> n;

    vector<vector<int>> arr = scan_2d_vector<int>(2, n);

    // cout << s.maxSum(n, arr);
    cout << s.maxSumBottomTop(n, arr);

    return 0;
}