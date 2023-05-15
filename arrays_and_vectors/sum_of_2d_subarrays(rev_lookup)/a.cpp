#include <bits/stdc++.h>

using namespace std;

typedef long long int llt;

#define mod 1000000007

llt get_2d_subarrays_sum(vector<vector<llt>> v, llt m, llt n)
{
    llt ans = 0;

    for (llt i = 0; i < m; i++)
    {
        for (llt j = 0; j < n; j++)
        {
            ans += (((((((i + 1) % mod) * ((j + 1) % mod) % mod) *
                       ((((m - i) % mod) * ((n - j) % mod)) % mod)) %
                      mod) *
                     (v[i][j] % mod)) %
                    mod);
        }
    }

    return ans;
}

template <typename T>
void print_vector(vector<vector<T>> arr)
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

    llt m, n, value;

    cin >> m >> n;

    vector<vector<llt>> v(m, vector<llt>(n));

    for (llt i = 0; i < m; i++)
    {
        for (llt j = 0; j < n; j++)
        {
            cin >> value;
            v[i][j] = value;
        }
    }

    print_vector<llt>(v);

    cout << get_2d_subarrays_sum(v, m, n);

    return 0;
}