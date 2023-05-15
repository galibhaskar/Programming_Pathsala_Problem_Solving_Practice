#include <bits/stdc++.h>

using namespace std;

template <typename T>
void print_2d_vector(vector<vector<T>> arr)
{
    cout << "-------vector begin-----" << endl;

    for (auto ele : arr)
    {
        for (auto i : ele)
            cout << i << " ";
        cout << endl;
    }

    cout << "-------vector end-----" << endl;
}

class Solution
{
public:
    void calculate_matrix_sum(vector<vector<int>> &v, int m, int n, int k)
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

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (i != 0)
                    psum[i][j] = psum[i - 1][j] + psum[i][j];

        print_2d_vector<int>(psum);

        int x1, x2, y1, y2, total_sum;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                x1 = max(i - k, 0);
                y1 = max(j - k, 0);
                x2 = min(i + k, m - 1);
                y2 = min(j + k, n - 1);

                total_sum = psum[x2][y2];

                if (x1 - 1 >= 0)
                    total_sum -= psum[x1 - 1][y2];

                if (y1 - 1 >= 0)
                    total_sum -= psum[x2][y1 - 1];

                if (x1 - 1 >= 0 && y1 - 1 >= 0)
                    total_sum += psum[x1 - 1][y1 - 1];

                cout << " x1:" << x1 << " y1:" << y1 << " x2:" << x2 << " y2:"
                     << y2 << " total sum:" << total_sum << endl;

                v[i][j] = total_sum;
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
    int m, n, k;

    cin >> m >> n >> k;

    vector<vector<int>> v = scan_2d_vector<int, int>(m, n);

    Solution s;

    s.calculate_matrix_sum(v, m, n, k);

    print_2d_vector<int>(v);

    return 0;
}