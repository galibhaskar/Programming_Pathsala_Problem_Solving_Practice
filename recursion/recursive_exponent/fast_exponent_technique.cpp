#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    double fast_exponent(double n, int k)
    {
        if (k < 0)
        {
            n = 1 / n;
            k = -k;
        }

        cout << "n:" << n << endl;

        if (k == 0)
            return 1;

        double x = fast_exponent(n, k / 2);

        // odd k
        if (k % 2)
            return n * x * x;

        // even k
        else
            return x * x;
    }
};

int main(int argc, char const *argv[])
{

    Solution s;

    int n, k;

    cin >> n >> k;

    cout << s.fast_exponent(n, k);

    return 0;
}

// space and time complexity (max recursion stack with all function calls): O(logK)