#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long int llt;

llt get_max_expression_value(vector<llt> &v, llt n, llt p, llt q, llt r)
{
    vector<llt> pmax(n, 0), smax(n, 0);

    pmax[0] = p * v[0];
    smax[n - 1] = r * v[n - 1];

    for (llt i = 1; i < n; i++)
    {
        pmax[i] = max(pmax[i - 1], p * v[i]);
        smax[n - i - 1] = max(smax[n - i], r * v[n - i - 1]);
    }

    llt max_value = LLONG_MIN;

    // for (int i = 0; i < n; i++)
    //     for (int j = i; j < n; j++)
    //         for (int k = j; k < n; k++)
    //         {
    //             max_value = max(max_value, p * pmax[i] + q * v[j] + r * smax[k]);
    //             // cout << "max: " << max_value << " i:" << i << " j:" << j << " k:" << k << endl;
    //         }

    for (llt j = 0; j < n; j++)
        max_value = max(max_value, pmax[j] + q * v[j] + smax[j]);

    return max_value;
}

int main(int argc, char const *argv[])
{
    llt n, p, q, r, num;

    vector<llt> v;

    cin >> n >> p >> q >> r;

    while (n--)
    {
        cin >> num;
        v.push_back(num);
    }

    cout << get_max_expression_value(v, v.size(), p, q, r) << endl;

    return 0;
}