#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int NthRoot(int n, int m)
    {
        int low = 0, high = m - 1, mid;

        while (low <= high)
        {
            mid = low + ((high - low) / 2);

            if (pow(mid, n) == m)
                return mid;

            else if (pow(mid, n) < m)
                low = mid + 1;

            else
                high = mid - 1;
        }

        return -1;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;

    // s.f();

    return 0;
}