#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    void print_prime_factorization(int num)
    {
        int n = num, count;

        for (int i = 2; i * i < num; i++)
        {
            count = 0;

            while (n % i == 0)
            {
                count++;

                n /= i;
            }

            if (count != 0)
                cout << i << "^" << count << " ";
        }

        if (n != 1)
            cout << n << "^1" << endl;
    }
};

int main(int argc, char const *argv[])
{

    int n;

    cin >> n;

    Solution s;

    s.print_prime_factorization(n);

    return 0;
}