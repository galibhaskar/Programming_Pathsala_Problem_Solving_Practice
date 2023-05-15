#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int get_longer_set_size(vector<int> &v, int size)
    {
        if (size <= 1)
            return size;

        int max_set_size = INT_MIN, set_size = 1, j, temp;

        for (int i = 0; i < size; i++)
        {
            if (v[i] > 0)
            {
                j = v[i];

                v[i] = INT_MIN;

                while (i != j)
                {
                    set_size++;

                    temp = v[j];

                    v[j] = INT_MIN;

                    j = temp;
                }

                max_set_size = max(max_set_size, set_size);

                set_size = 1;
            }
        }

        return max_set_size;
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

int main(int argc, char const *argv[])
{
    vector<int> v = scan_vector<int, int>();

    Solution s;

    cout << s.get_longer_set_size(v, v.size()) << endl;

    return 0;
}