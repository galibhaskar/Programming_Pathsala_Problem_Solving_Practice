#include <bits/stdc++.h>

using namespace std;

typedef long long int llt;

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

pair<llt, llt> get_indices_of_key_in_2d_array(vector<vector<llt>> v, llt key)
{
    llt i = 0, j = v[0].size() - 1;

    while (i < v.size() && j >= 0)
    {
        if (v[i][j] == key)
            return {i, j};

        else if (v[i][j] > key)
            j--;

        else
            i++;
    }

    return {-1, -1};
}

int main(int argc, char const *argv[])
{

    vector<vector<llt>> v = scan_2d_vector<llt>();

    llt key;

    cin >> key;

    pair<llt, llt> result = get_indices_of_key_in_2d_array(v, key);

    cout << result.first << " " << result.second << endl;
    return 0;
}