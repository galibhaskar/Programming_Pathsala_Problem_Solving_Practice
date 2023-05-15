// sieve of eratostheses
// time complexity: O(N(lg(lgN)))
// space complexity: O(N)

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    void print_primes_in_range(int range)
    {
        vector<bool> nums(range + 1, 1);

        for (int i = 2; i * i <= range; i++)
        {
            if (nums[i])
            {
                for (int j = i * i; j < range; j += i)
                    if (nums[j])
                        nums[j] = 0;
            }
        }

        for (int i = 2; i < range; i++)
            if (nums[i])
                cout << i << " ";
    }
};

int main(int argc, char const *argv[])
{
    Solution s;

    int range;

    cin >> range;

    s.print_primes_in_range(range);

    return 0;
}