#include <bits/stdc++.h>

using namespace std;

typedef long long int llt;

#define mod 1000000007

template <typename T, typename size_type>
vector<T> scan_vector()
{
    vector<T> arr;

    size_type n;

    cin >> n;

    T input;

    while (n--)
    {
        cin >> input;
        arr.push_back(input);
    }

    return arr;
}

llt sum_of_all_subarrays(vector<llt> v)
{
    llt total_sum = 0;

    for (auto i = 0; i < v.size(); i++)
        total_sum = (total_sum % mod +
                     ((((((i + 1) % mod) * ((v.size() - i) % mod)) % mod) * (v[i] % mod)) % mod)) %
                    mod;

    return total_sum;
}

int main(int argc, char const *argv[])
{
    vector<llt> v = scan_vector<llt, llt>();

    cout << sum_of_all_subarrays(v);

    return 0;
}