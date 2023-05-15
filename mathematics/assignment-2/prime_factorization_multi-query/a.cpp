#include <bits/stdc++.h>

using namespace std;

class Solution
{
private:
    vector<int> spf;

public:
    void get_spf_in_range(int range)
    {
        spf = vector<int>(range + 1, -1);

        spf[0] = spf[1] = 1;

        for (int i = 2; i * i <= range; i++)
        {
            if (spf[i] == -1)
            {
                for (int j = i * i; j <= range; j += i)
                {
                    if (spf[j] == -1)
                        spf[j] = i;
                }
            }
        }
    }

    void print_prime_factors(int num)
    {
        int count;

        map<int, int> prime_factors;

        while (spf[num] != -1)
        {
            prime_factors[spf[num]]++;
            num /= spf[num];
        }

        if (spf[num] == -1)
            prime_factors[num]++;

        for (auto i : prime_factors)
            cout << i.first << " " << i.second << endl;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;

    int test_cases, N;

    cin >> test_cases;

    s.get_spf_in_range(1000000);

    while (test_cases--)
    {
        cin >> N;

        s.print_prime_factors(N);
    }

    return 0;
}