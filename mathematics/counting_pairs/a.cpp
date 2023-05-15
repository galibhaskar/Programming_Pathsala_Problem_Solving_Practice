#include <bits/stdc++.h>

using namespace std;

class Solution
{
private:
    int calculate_combination(int n)
    {
        return (n * (n - 1)) / 2;
    }

public:
    int get_pairs_count(vector<int> arr, int k)
    {
        vector<int> buckets(k, 0);

        for (auto i : arr)
            buckets[i % k]++;

        int pairs_count = calculate_combination(buckets[0]);

        for (int i = 1; i <= (k / 2) - 1; i++)
            pairs_count += (buckets[i] * buckets[k - i]);

        if (k % 2)
            pairs_count += (buckets[k / 2] * buckets[(k / 2) + 1]);

        else
            pairs_count += calculate_combination(buckets[k / 2]);

        return pairs_count;
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
    Solution s;

    vector<int> arr = scan_vector<int, int>();

    int k;

    cin >> k;

    cout << s.get_pairs_count(arr, k) << endl;

    return 0;
}