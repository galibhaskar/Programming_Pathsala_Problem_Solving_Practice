#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int get_majority_using_boyer_moore_algorithm(vector<int> &v, int size)
    {
        int votes = 0, majority_element = -1;

        for (auto elem : v)
        {
            if (votes == 0)
                majority_element = elem;

            votes += (majority_element == elem ? 1 : -1);
        }

        int count = 0;

        for (auto x : v)
        {
            if (x == majority_element)
                count++;
        }

        cout << "majority_element " << majority_element << endl;

        if (count > size / 2)
            return majority_element;

        return -1;
    }

    int get_majority_element(vector<int> &v, int size)
    {
        map<int, int> m;

        for (auto i : v)
        {
            m[i]++;

            if (m[i] > (size / 2))
                return i;
        }

        return 0;
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

    cout << s.get_majority_using_boyer_moore_algorithm(v, v.size());

    // cout << s.get_majority_element(v, v.size());

    return 0;
}