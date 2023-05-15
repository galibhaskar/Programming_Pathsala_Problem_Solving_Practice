#include <bits/stdc++.h>

using namespace std;

#define mod 1000000007

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

long long int get_sum_of_2d_array(vector<vector<int>> psum, int m, int n)
{
    int x1, y1, x2, y2;

    cin >> x1 >> y1 >> x2 >> y2;

    long long int total_sum = psum[x2][y2];

    cout << total_sum << " x1:" << x1 << " y1" << y1 << " x2:" << x2 << " y2" << y2 << endl;

    if (x1 - 1 >= 0)
        total_sum = (total_sum % mod - psum[x1 - 1][y2] % mod) % mod;

    if (y1 - 1 >= 0)
        total_sum = (total_sum % mod - psum[x2][y1 - 1] % mod) % mod;

    if (x1 - 1 >= 0 && y1 - 1 >= 0)
        total_sum = (total_sum % mod + psum[x1 - 1][y1 - 1] % mod) % mod;

    return total_sum;
}

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

int main(int argc, char const *argv[])
{
    int m, n, test_cases;

    cin >> m >> n;

    vector<vector<int>> v = scan_2d_vector<int, int>(m, n);

    // calculating the prefix sum of the 2d array
    vector<vector<int>> psum(m, vector<int>(n));

    // row-wise sum
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

    // col-wise sum
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            if (i != 0)
                psum[i][j] = psum[i - 1][j] + psum[i][j];

    print_2d_vector<int>(psum);

    cin >> test_cases;

    while (test_cases--)
        cout << get_sum_of_2d_array(psum, m, n) << endl;

    return 0;
}