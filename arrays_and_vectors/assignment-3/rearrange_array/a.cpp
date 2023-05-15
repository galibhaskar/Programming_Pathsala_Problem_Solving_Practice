#include <bits/stdc++.h>

using namespace std;

typedef long long int llt;

template <typename T>
void print_vector(vector<T> arr)
{
    for (auto ele : arr)
        cout << ele << " ";
}

class Solution
{
public:
    void rearrange_array(vector<llt> &v, llt size)
    {
        llt old_value, new_value;

        for (llt i = 0; i < size; i++)
        {
            old_value = v[i] % size;
            v[old_value] = size * i + v[old_value];
        }

        for (llt i = 0; i < size; i++)
            v[i] /= size;
    }
};

template <typename T, typename size_type>
vector<T> scan_vector(size_type size = 0)
{
    size_type n;

    if (size == 0)
        cin >> n;

    else
        n = size;

    vector<T> arr(n);

    for (auto i = 0; i < n; i++)
        cin >> arr[i];

    return arr;
}

int main(llt argc, char const *argv[])
{
    vector<llt> v = scan_vector<llt, llt>();

    Solution s;

    s.rearrange_array(v, v.size());

    print_vector<llt>(v);

    return 0;
}