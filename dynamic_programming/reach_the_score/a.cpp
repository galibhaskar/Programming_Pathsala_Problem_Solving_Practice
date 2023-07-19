#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    long long int count(long long int n)
    {
        long long int table[n + 1], i;

        for (long long int i = 0; i <= n; i++)
            table[i] = 0;

        table[0] = 1;

        for (long long int i = 3; i <= n; i++)
            table[i] += table[i - 3];

        for (long long int i = 5; i <= n; i++)
            table[i] += table[i - 5];

        for (long long int i = 10; i <= n; i++)
            table[i] += table[i - 10];

        return table[n];
    }
};

int main(int argc, char const *argv[])
{
    Solution s;

    int test_cases;

    cin >> test_cases;

    long long int num;

    while (test_cases--)
    {
        cin >> num;

        cout << s.count(num) << endl;
    }

    return 0;
}