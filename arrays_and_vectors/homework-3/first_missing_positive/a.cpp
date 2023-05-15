#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long int llt;

class Solution
{
public:
    llt get_missing_positive(vector<llt> &v)
    {
        vector<bool> positive_numbers(pow(2, 31) - 1, false);

        for (auto i : v)
        {
            if (i > 0)
                positive_numbers[i] = true;
        }

        for (int i = 1; i < positive_numbers.size(); i++)
            if (!positive_numbers[i])
                return i;

        return -1;
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
    llt test_cases;

    cin >> test_cases;

    Solution s;

    while (test_cases--)
    {
        vector<llt> v = scan_vector<llt, llt>();

        cout << s.get_missing_positive(v) << endl;
    }
    return 0;
}