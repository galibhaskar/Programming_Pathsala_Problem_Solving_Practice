#include <bits/stdc++.h>

using namespace std;

typedef long long int llt;
class Solution
{
private:
    // euclid gcd algorithm
    llt get_gcd(llt a, llt b)
    {
        if (a > b)
            swap(a, b);

        if (a == 0)
            return b;

        return get_gcd(b % a, a);
    }

    llt get_lcm(llt a, llt b)
    {
        return (a * b) / get_gcd(a, b);
    }

public:
    bool can_win(llt n, llt a, llt b, llt k)
    {
        llt total_problems_of_bob = n / a, total_problems_of_alice = n / b, common_problems = (n / get_lcm(a, b));

        return (total_problems_of_alice + total_problems_of_bob - 2 * common_problems >= k);
    }
};

int main(int argc, char const *argv[])
{
    int test_cases;

    cin >> test_cases;

    llt n, a, b, k;

    Solution s;

    while (test_cases--)
    {
        cin >> n >> a >> b >> k;

        cout << (s.can_win(n, a, b, k) ? "Win" : "Lose") << endl;
    }

    return 0;
}