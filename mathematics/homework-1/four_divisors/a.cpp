#include <bits/stdc++.h>

using namespace std;

class Solution
{
private:
    int get_four_divisors_sum_of_num(int num)
    {
        int sqrt_num = sqrt(num);

        bool is_perfect_square = (sqrt_num * sqrt_num == num);

        // odd divisors
        if (is_perfect_square)
            return 0;

        int divisors_count = 2, divisors_sum = 0;

        // cout << "num: " << num << endl;

        // even divisors
        for (auto i = 1; i * i <= num; i++)
        {
            if (num % i == 0)
            {
                // cout << "div1:" << i << " div2:" << num / i << endl;

                if (divisors_count == 0)
                    return 0;

                divisors_sum += (i);
                divisors_sum += (num / i);

                divisors_count--;
            }
        }

        if (divisors_count == 0)
        {
            // cout << "sum:" << divisors_sum << endl;

            return divisors_sum;
        }

        return 0;
    }

public:
    int get_four_divisors_sum(vector<int> &v, int size)
    {
        long long int total_sum = 0;

        for (auto num : v)
            total_sum += get_four_divisors_sum_of_num(num);

        return total_sum;
    }
};

template <typename T, typename size_type>
vector<T> scan_vector(size_type size = 0)
{
    size_type n;

    if (size == 0)
        cin >> n;

    else
        n = size;

    vector<T> arr(n);

    for (auto i = 0; i < n; i++)
        cin >> arr[i];

    return arr;
}

int main(int argc, char const *argv[])
{
    int test_cases;

    cin >> test_cases;

    vector<int> v;

    Solution s;

    while (test_cases--)
    {
        v = scan_vector<int, int>();

        cout << s.get_four_divisors_sum(v, v.size()) << endl;
    }

    return 0;
}