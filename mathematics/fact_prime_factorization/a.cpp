#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    void fast_prime_factorization(int num)
    {
        // map<int, int> pf;

        vector<int> spf(num + 1, -1);

        for (int i = 2; i * i <= num; i++)
        {
            if (spf[i] == -1)
            {
                for (int j = i * i; j <= num; j += i)
                    if (spf[j] == -1)
                        spf[j] = i;
            }
        }

        // for (int i = 2; i <= num; i++)
        // {
        //     if (spf[i] == -1)
        //         cout << i << " ";
        // }

        while (num >= 1 && spf[num] != -1)
        {
            cout << spf[num] << " ";
            num /= spf[num];
        }

        if (num != 1)
            cout << num << endl;
    }
};

int main(int argc, char const *argv[])
{
    int num;

    cin >> num;

    Solution s;

    s.fast_prime_factorization(num);

    return 0;
}