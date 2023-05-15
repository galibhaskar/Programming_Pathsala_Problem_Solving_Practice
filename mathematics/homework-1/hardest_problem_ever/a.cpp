#include <bits/stdc++.h>

using namespace std;

typedef long long int llt;

class Solution
{
private:
    llt get_gcd(llt a, llt b)
    {
        if (a > b)
            swap(a, b);

        if (a == 0)
            return b;

        return get_gcd(b % a, a);
    }

public:
    bool is_correct_output(vector<llt> &v)
    {
        if (v.size() == 1)
            return 0;

        llt gcd = get_gcd(v[0], v[1]);

        if (gcd == 1)
            return 1;

        for (auto i = 2; i < v.size(); i++)
        {
            gcd = get_gcd(gcd, v[i]);

            if (gcd == 1)
                return 1;
        }

        if (gcd == 1)
            return 1;

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
    int test_cases;

    cin >> test_cases;

    Solution s;

    while (test_cases--)
    {
        vector<llt> v = scan_vector<llt, int>();

        cout << s.is_correct_output(v) << endl;
    }

    return 0;
}