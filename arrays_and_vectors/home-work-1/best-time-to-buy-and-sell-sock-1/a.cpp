#include <bits/stdc++.h>

using namespace std;

typedef long long int llt;

template <typename T>
vector<T> scan_vector()
{
    vector<T> arr;

    int n;

    cin >> n;

    T input;

    while (n--)
    {
        cin >> input;
        arr.push_back(input);
    }

    return arr;
}

llt get_max_profit(vector<llt> v, int size)
{
    if (size <= 1)
        return 0;

    vector<llt> pmin(size, LONG_LONG_MAX), smax(size, LONG_LONG_MIN);

    llt profit = LONG_LONG_MIN, value;

    pmin[0] = v[0];

    smax[size - 1] = v[size - 1];

    // finding the prefix min and suffix max
    for (llt i = 1; i < size; i++)
    {
        pmin[i] = min(pmin[i - 1], v[i]);
        smax[size - i - 1] = max(smax[size - i], v[size - i - 1]);
    }

    // finding the max profit
    for (llt i = 0; i < size; i++)
    {
        value = smax[i] - pmin[i];
        if (profit < value)
            profit = value;
    }

    return profit;
}

int main(int argc, char const *argv[])
{
    vector<llt> v = scan_vector<llt>();

    cout << get_max_profit(v, v.size());

    return 0;
}