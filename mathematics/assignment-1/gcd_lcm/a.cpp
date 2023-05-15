#include <bits/stdc++.h>

using namespace std;

typedef long long int llt;

class Solution
{
public:
    llt get_gcd(llt a, llt b)
    {
        if (a > b)
            swap(a, b);

        if (a == 0)
            return b;

        return get_gcd(b % a, a);
    }
};

int main(int argc, char const *argv[])
{
    llt a, b;

    cin >> a >> b;

    Solution s;

    llt gcd = s.get_gcd(a, b), lcm = (a * b) / gcd;

    cout << gcd << " " << lcm;

    return 0;
}