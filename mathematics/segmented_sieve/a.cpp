#include <bits/stdc++.h>
#include <iostream>

#define max_range 1000000

using namespace std;

class Solution
{
public:
    vector<long long int> get_primes(int range)
    {
        // cout << range << endl;

        vector<long long int> primes;

        vector<bool> is_prime(range + 1, 1);

        for (long long int i = 2; i * i <= range; i++)
        {
            if (is_prime[i])
            {
                for (long long int j = i * i; j <= range; j += i)
                    if (is_prime[j])
                        is_prime[j] = 0;
            }
        }

        for (long long int i = 2; i <= range; i++)
            if (is_prime[i])
                primes.push_back(i);

        // cout << "primes size:" << primes.size() << endl;

        return primes;
    }

    void print_primes_in_range(vector<long long int> &primes, long long int left, long long int right)
    {
        vector<long long int> spf(right - left + 1, -1);

        for (long long int prime_number : primes)
        {
            if (prime_number * prime_number > right)
                break;

            for (long long int k = ceil(left / (double)prime_number);
                 k * prime_number <= right; k++)
            {
                if (spf[(prime_number * k) - left] == -1)
                    spf[(prime_number * k) - left] = prime_number;
            }
        }

        for (long long int i = 0; i < spf.size(); i++)
        {
            if (spf[i] == -1 && (i + left) != 1)
                cout << (i + left) << " ";
        }
        cout << endl;
    }
};

int main(int argc, char const *argv[])
{

    long long int test_cases, left, right;

    cin >> test_cases;

    Solution s;

    vector<pair<int, int>> test_cases_data;

    long long int max_right_value = -1;

    while (test_cases--)
    {
        cin >> left >> right;

        test_cases_data.push_back({left, right});

        max_right_value = max(max_right_value, right);
    }

    vector<long long int> primes = s.get_primes(max_right_value);

    for (auto element : test_cases_data)
        s.print_primes_in_range(primes, element.first, element.second);

    return 0;
}