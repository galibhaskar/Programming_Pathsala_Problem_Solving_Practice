#include <bits/stdc++.h>

using namespace std;

typedef long long int llt;

llt get_min_swaps(vector<llt> v, llt k)
{
    llt sliding_window_size = 0;

    for (auto i : v)
        if (i <= k)
            sliding_window_size++;

    cout << sliding_window_size << endl;

    llt max_valid_elements_in_window = INT_MIN, i = 0, valid_elements_count = 0;

    while (i < sliding_window_size)
    {
        if (v[i++] <= k)
            valid_elements_count++;
    }

    max_valid_elements_in_window = max(max_valid_elements_in_window, valid_elements_count);

    cout << max_valid_elements_in_window << endl;

    while (i < v.size())
    {
        if (v[i - sliding_window_size] <= k)
            valid_elements_count--;

        if (v[i] <= k)
            valid_elements_count++;

        max_valid_elements_in_window = max(max_valid_elements_in_window, valid_elements_count);

        i++;
    }

    return (sliding_window_size - max_valid_elements_in_window);
}

template <typename T, typename size_type>
vector<T> scan_vector(size_type size = 0)
{
    vector<T> arr;

    size_type n;

    if (size == 0)
        cin >> n;

    else
        n = size;

    T input;

    while (n--)
    {
        cin >> input;
        arr.push_back(input);
    }

    return arr;
}

int main(int argc, char const *argv[])
{
    llt n, k;

    cin >> n >> k;

    vector<llt> v = scan_vector<llt, llt>(n);

    cout << get_min_swaps(v, k);

    return 0;
}