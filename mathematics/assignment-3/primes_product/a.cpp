#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<int> get_primes(int size)
    {
        // cout << "size:" << sqrt(size) << endl;
        vector<int> is_prime(size + 1, 1);

        vector<int> primes;

        is_prime[0] = is_prime[1] = 0;

        for (int i = 2; i * i <= size; i++)
        {
            if (is_prime[i])
            {
                for (int j = i * i; j <= size; j += i)
                {
                    if (is_prime[j])
                        is_prime[j] = 0;
                }
            }
        }

        for (int i = 2; i <= size; i++)
            if (is_prime[i])
            {
                primes.push_back(i);
                // cout << i << endl;
            }

        return primes;
    }

    long long calculate_product(long long L, long long R)
    {
        int range = sqrt(R);

        // cout << range << endl;

        long long product = 1;

        // if (L < 2)
        //     L = 2;

        vector<int> primes_in_range(R - L, 1);

        vector<int> primes = get_primes(range);

        for (auto i : primes)
        {
            // cout << i << endl;
            // cout << ceil(L * 1.0 / i) << endl;
            for (int j = ceil((L * 1.0) / i); j * i <= R; j++)
            {
                cout << "value:" << (j * i) - L << endl;
                if (primes_in_range[(j * i) - L])
                    primes_in_range[(j * i) - L] = 0;
            }
        }

        for (int j = 0; j < R - L; j++)

            if (primes_in_range[j])
            {
                cout << L + j << endl;
                product *= (L + j);
            }

        return product;
    }
};

int main(int argc, char const *argv[])
{

    Solution s;

    int L, R;

    cin >> L >> R;

    cout << s.calculate_product(L, R);
    return 0;
}