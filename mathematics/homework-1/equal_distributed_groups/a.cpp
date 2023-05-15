#include <bits/stdc++.h>

using namespace std;

class Solution
{
private:
    int get_gcd(int a, int b)
    {
        if (a > b)
            swap(a, b);

        if (a == 0)
            return b;

        return get_gcd(b % a, a);
    }

public:
    bool can_equally_distribute(vector<int> &v)
    {
        map<int, int> freq;

        for (auto i : v)
            freq[i]++;

        int gcd = get_gcd(freq.begin()->second, next(freq.begin(), 1)->second);

        for (auto i = next(freq.begin(), 2); i != freq.end(); i++)
        {
            if (gcd == 1)
                return false;

            gcd = get_gcd(gcd, i->second);
        }

        if (gcd >= 2)
            return true;

        return false;
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
        vector<int> v = scan_vector<int, int>();

        cout << (s.can_equally_distribute(v) ? "true" : "false");
    }

    return 0;
}