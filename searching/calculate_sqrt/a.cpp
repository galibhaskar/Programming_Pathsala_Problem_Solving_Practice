#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    long long int calculate_sqrt(long long int n)
    {
        long long int low = 0, high = n - 1, mid;

        while (low <= high)
        {
            mid = low + ((high - low) / 2);

            if (mid * mid == n)
                return mid;

            if (mid * mid < n)
                low = mid + 1;

            else
            {
                if ((mid - 1) * (mid - 1) <= n)
                    return (mid - 1);

                else
                    high = mid - 1;
            }
        }

        return 1;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;

    int n;

    cin >> n;

    cout << s.calculate_sqrt(n);

    return 0;
}