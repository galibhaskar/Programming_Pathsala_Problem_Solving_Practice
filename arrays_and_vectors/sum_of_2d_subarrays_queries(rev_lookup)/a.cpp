#include <bits/stdc++.h>

using namespace std;

typedef long long int llt;

#define mod 1000000007

template <typename T>
vector<vector<T>> scan_2d_vector()
{
    int m, n, i = 0, j;

    cin >> m >> n;

    vector<vector<T>> arr(m, vector<T>(n));

    T input;

    for (auto i = 0; i < m; i++)
    {
        for (auto j = 0; j < n; j++)
        {
            cin >> input;

            arr[i][j] = input;
        }
    }

    return arr;
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

llt get_sum_of_2d_subarray_of_range(vector<vector<llt>> v, llt i1, llt j1, llt i2, llt j2)
{
    llt total_sum = 0;

    vector<vector<llt>> psum(v.size(), vector<llt>(v[0].size()));

    // calculating the prefix max of complete 2d array
    // row-wise
    for (auto i = 0; i < v.size(); i++)
    {
        for (auto j = 0; j < v[i].size(); j++)
        {
            if (j == 0)
                psum[i][j] = v[i][j];

            else
                psum[i][j] = psum[i][j - 1] + v[i][j];
        }
    }

    // col-wise
    for (auto i = 1; i < v.size(); i++)
        for (auto j = 0; j < v[i].size(); j++)
            psum[i][j] = psum[i - 1][j] + psum[i][j];

    // print_2d_vector(psum);

    total_sum = psum[i2][j2] % mod;

    // subtracting the sum of area1 elements.
    if ((i1 - 1) >= 0)
        total_sum = (total_sum % mod - psum[i1 - 1][j2] % mod) % mod;

    // subtracting the sum of area2 elements.
    if ((j1 - 1) >= 0)
        total_sum = (total_sum % mod - psum[i2][j1 - 1] % mod) % mod;

    // adding the sum of common area elements which is subtracted twice.
    if ((i1 - 1) >= 0 && (j1 - 1) >= 0)
        total_sum = (total_sum % mod + psum[i1 - 1][j1 - 1] % mod) % mod;

    return total_sum;
}

int main(int argc, char const *argv[])
{

    vector<vector<llt>> v = scan_2d_vector<llt>();

    llt queries_count, i1, i2, j1, j2;

    cin >> queries_count;

    while (queries_count--)
    {
        cin >> i1 >> j1 >> i2 >> j2;

        cout << get_sum_of_2d_subarray_of_range(v, i1, j1, i2, j2);
    }

    return 0;
}