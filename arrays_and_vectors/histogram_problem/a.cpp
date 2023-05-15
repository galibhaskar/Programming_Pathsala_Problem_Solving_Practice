/*
Given an array of heights, find the maximum amount of water that gets trapped.

*/

#include <bits/stdc++.h>

using namespace std;

void print_vector(vector<int> v)
{
    cout << "-----------vector begin ----------" << endl;
    for (auto i : v)
        cout << i << " ";
    cout << endl;
}

int find_water_trapped_amount(vector<int> &v)
{
    int n = v.size();

    int total_water_height = 0;

    vector<int> prefix_max(n, 0), suffix_max(n, 0);

    prefix_max[0] = v[0];

    suffix_max[n - 1] = v[n - 1];

    for (int i = 1, j = n - 2; i < n, j >= 0; i++, j--)
    {
        prefix_max[i] = max(prefix_max[i - 1], v[i]);
        suffix_max[j] = max(suffix_max[j + 1], v[j]);
    }

    print_vector(prefix_max);

    print_vector(suffix_max);

    int h1, h2;

    for (int i = 1; i < n - 1; i++)
    {
        h1 = prefix_max[i];
        h2 = suffix_max[i];

        int cumm_height = min(h1, h2);

        if (cumm_height > v[i])
            total_water_height += (cumm_height - v[i]);
    }

    return total_water_height;
}

int main(int argc, char const *argv[])
{
    int n, num;
    cin >> n;
    vector<int> v(0, n);
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        v.push_back(num);
    }

    cout << "total height" << find_water_trapped_amount(v) << endl;
    return 0;
}
