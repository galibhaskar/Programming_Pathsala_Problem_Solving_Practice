#include <bits/stdc++.h>

using namespace std;

class Solution
{
private:
    void populate_spf_vector(vector<int> &spf, int num)
    {
        for (int i = 2; i * i <= num; i++)
        {
            if (spf[i] == -1)
            {
                for (int j = i * i; j <= num; j += i)
                    if (spf[j] == -1)
                        spf[j] = i;
            }
        }
    }

public:
    int get_divisors_count(int num)
    {
        vector<int> spf(num + 1, -1);

        populate_spf_vector(spf, num);

        map<int, int> prime_factors;

        while (spf[num] != -1)
        {
            prime_factors[spf[num]]++;

            num /= spf[num];
        }

        if (num != 1)
            prime_factors[num]++;

        int divisors_count = 1;

        for (auto i : prime_factors)
        {
            cout << i.first << "^" << i.second << " ";
            divisors_count *= (i.second + 1);
        }

        return divisors_count;
    }
};

int main(int argc, char const *argv[])
{
    int num, test_cases;

    cin >> test_cases;

    Solution s;

    while (test_cases--)
    {
        cin >> num;

        cout << "num:" << num << " divisiors:" << s.get_divisors_count(num) << endl;
    }

    return 0;
}