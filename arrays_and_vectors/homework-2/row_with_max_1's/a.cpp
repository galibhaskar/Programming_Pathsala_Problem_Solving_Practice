#include <bits/stdc++.h>

using namespace std;

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

class Solution
{
public:
    int get_row_with_max_ones(vector<vector<int>> &v, int m, int n)
    {
        vector<vector<int>> psum(m, vector<int>(n));

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (j == 0)
                    psum[i][j] = v[i][j];

                else
                    psum[i][j] = psum[i][j - 1] + v[i][j];
            }
        }

        int max_ones_count = 0, index = -1;

        for (int i = 0; i < m; i++)
        {
            if (max_ones_count < psum[i][n - 1])
            {
                max_ones_count = psum[i][n - 1];
                index = i;
            }
        }

        return index;
    }
};

int main(int argc, char const *argv[])
{
    int m, n;

    cin >> m >> n;

    vector<vector<int>> v = scan_2d_vector<int, int>(m, n);

    Solution s;

    cout << s.get_row_with_max_ones(v, m, n);

    return 0;
}