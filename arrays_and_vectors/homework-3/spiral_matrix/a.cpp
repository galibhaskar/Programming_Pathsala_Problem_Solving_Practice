#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    void get_spiral_matrix(vector<vector<int>> &v, int m, int n)
    {
        int row_start = 0, row_end = m - 1, col_start = 0, col_end = n - 1;

        if (m == 1)
        {
            for (int i = 0; i < n; i++)
                cout << v[0][i] << " ";

            return;
        }

        if (n == 1)
        {
            for (int i = 0; i < m; i++)
                cout << v[i][0] << " ";

            return;
        }

        while (row_start <= row_end && col_start <= col_end)
        {
            for (int i = col_start; i <= col_end; i++)
                cout << v[row_start][i] << " ";

            row_start++;

            for (int i = row_start; i <= row_end; i++)
                cout << v[i][col_end] << " ";

            col_end--;

            if (row_start <= row_end && col_start <= col_end)
            {
                for (int i = col_end; i >= col_start; i--)
                    cout << v[row_end][i] << " ";

                row_end--;
            }

            if (row_start <= row_end && col_start <= col_end)
            {
                for (int i = row_end; i >= row_start; i--)
                    cout << v[i][col_start] << " ";

                col_start++;
            }
        }
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
    int m, n;

    cin >> m >> n;

    vector<vector<int>> v = scan_2d_vector<int, int>(m, n);

    Solution s;

    s.get_spiral_matrix(v, m, n);

    return 0;
}