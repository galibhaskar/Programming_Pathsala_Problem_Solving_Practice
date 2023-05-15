/*
    Given an array of even and odd numbers.

    Separate the even and odd numbers preserving their order.

    space complexity should be O(1)
*/

#include <bits/stdc++.h>

using namespace std;

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

template <typename T>
void print_vector(vector<T> arr)
{
    cout << "-------vector begin-----" << endl;

    for (auto ele : arr)
        cout << ele << " ";

    cout << endl
         << "-------vector end-----" << endl;
}

class Solution
{
private:
    void rotate_vector_clock_wise(vector<int> &v, int start, int end, int k)
    {
        // print_vector<int>(v);

        // cout << "start:" << start << " end:" << end << " k:" << k << endl;

        int size = end - start;

        if (size == 0)
            return;

        if (k > size)
            k %= size;

        // reversing the elements from start to end using swapping.
        for (int i = 0; i <= size / 2; i++)
            swap(v[i + start], v[end - i]);

        // print_vector<int>(v);

        for (int i = 0; i <= k / 2; i++)
            swap(v[i + start], v[k + start - i - 1]);

        // print_vector<int>(v);

        for (int i = 0; i <= (size - k) / 2; i++)
            swap(v[i + start + k], v[end - i]);
    }

public:
    void separate_even_odd(vector<int> &v)
    {
        int last_even_index = -1;

        for (int i = 0; i < v.size(); i++)
        {
            if (v[i] % 2)
                continue;

            else
            {
                last_even_index++;
                rotate_vector_clock_wise(v, last_even_index, i, 1);
            }
        }

        print_vector<int>(v);
    }
};

int main(int argc, char const *argv[])
{
    vector<int> v = scan_vector<int, int>();

    Solution s;

    s.separate_even_odd(v);

    return 0;
}