#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int recursive_expononent(int n, int k)
    {
        if (k == 0)
            return 1;

        return n * recursive_expononent(n, k - 1);
    }
};

int main(int argc, char const *argv[])
{

    Solution s;

    int n, k;

    cin >> n >> k;

    cout << s.recursive_expononent(n, k);

    return 0;
}

// complexity: O(K)