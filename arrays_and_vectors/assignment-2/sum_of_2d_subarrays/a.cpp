#include <bits/stdc++.h>

using namespace std;

typedef long long int llt;

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

llt get_sum_of_2d_subarrays(vector<vector<llt>> v, llt m, llt n)
{
    llt total_sum = 0;

    for (llt i = 0; i < m; i++)
        for (llt j = 0; j < n; j++)
            total_sum = (total_sum % mod +
                         (((
                               (((i + 1) % mod * (j + 1) % mod) % mod) *
                               (((m - i) % mod * (n - j) % mod) % mod)) %
                           mod) *
                          (v[i][j] % mod)) %
                             mod) %
                        mod;

    return total_sum;
}

int main(int argc, char const *argv[])
{
    llt m, n;

    cin >> m >> n;

    vector<vector<llt>> v = scan_2d_vector<llt, llt>(m, n);

    cout << get_sum_of_2d_subarrays(v, m, n);

    return 0;
}