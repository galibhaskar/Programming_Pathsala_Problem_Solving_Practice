#include <bits/stdc++.h>

using namespace std;

class Solution
{
private:
    vector<long long> spf;

public:
    void get_spf_in_range(long long range)
    {
        spf = vector<long long>(range + 1, -1);

        spf[0] = spf[1] = 1;

        for (long long i = 2; i * i <= range; i++)
        {
            if (spf[i] == -1)
            {
                for (long long j = i * i; j <= range; j += i)
                {
                    if (spf[j] == -1)
                        spf[j] = i;
                }
            }
        }
    }

    void count_unique_primes(long long num)
    {
        set<long long> unique_prime_factors;

        if (num < 2)
            cout << 0 << " ";

        else
        {
            while (spf[num] != -1)
            {
                unique_prime_factors.insert(spf[num]);
                num /= spf[num];
            }

            if (spf[num] == -1)
                unique_prime_factors.insert(num);

            cout << unique_prime_factors.size() << " ";
        }
    }
};

int main(int argc, char const *argv[])
{
    Solution s;

    long long test_cases, N, element;

    cin >> test_cases;

    s.get_spf_in_range(1000000);

    while (test_cases--)
    {
        cin >> N;

        for (long long i = 0; i < N; i++)
        {
            cin >> element;

            s.count_unique_primes(element);
        }

        cout << endl;
    }

    return 0;
}