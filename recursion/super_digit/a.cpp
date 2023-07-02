#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    long long int combine_sum(long long int start, long long int end, string &digits)
    {
        if (start == end)
        {
            return digits[start] - '0';
        }

        long long int mid = (start + end) / 2;

        return combine_sum(start, mid, digits) + combine_sum(mid + 1, end, digits);
    }

    long long int get_super_digit(long long int n)
    {
        string num = to_string(n);

        if (num.length() == 1)
            return n;

        return get_super_digit(combine_sum(0, num.length() - 1, num));
    }

    long long int super_digit(string n, long long int k)
    {
        long long int num = combine_sum(0, n.length() - 1, n) * k;

        return get_super_digit(num);
    }
};

int main(int argc, char const *argv[])
{
    Solution s;

    string n;

    long long int k;

    cin >> n >> k;

    cout << s.super_digit(n, k);

    return 0;
}