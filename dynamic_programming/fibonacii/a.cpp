#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int fib(int n)
    {
        if (n < 2)
            return n;

        return fib(n - 1) + fib(n - 2);
    }
};

int main(int argc, char const *argv[])
{
    Solution s;

    for (int i = 0; i < 10; i++)
        cout << s.fib(i) << " ";

    return 0;
}