#include <bits/stdc++.h>

using namespace std;

template <typename T>
void print_vector(vector<T> arr)
{
    for (auto ele : arr)
        cout << ele << " ";
}

class Solution
{
public:
    int get_max_gap(vector<int> v, int size)
    {
        if (size < 2)
            return 0;

        int min_element = INT_MAX, max_element = INT_MIN;

        for (auto element : v)
        {
            min_element = min(min_element, element);
            max_element = max(max_element, element);
        }

        int diff = max_element - min_element, gap, bucket_no;

        if (diff % (size - 1))
            gap = (diff / (size - 1)) + 1;

        else
            gap = (diff / (size - 1));

        if (size == 2 || gap == 0)
            return diff;

        vector<int> min_bucket(size, INT_MAX), max_bucket(size, INT_MIN);

        for (int i = 0; i < size; i++)
        {
            bucket_no = (v[i] - min_element) / gap;

            min_bucket[bucket_no] = min(min_bucket[bucket_no], v[i]);

            max_bucket[bucket_no] = max(max_bucket[bucket_no], v[i]);
        }

        // print_vector<int>(min_bucket);

        // print_vector<int>(max_bucket);

        int prev_max_element = INT_MIN, max_consecutive_diff = INT_MIN;

        for (int i = 0; i < size; i++)
        {
            // cout << "index" << i << endl;

            if (min_bucket[i] == INT_MAX)
                continue;

            if (prev_max_element == INT_MIN)
                prev_max_element = max_bucket[i];

            else
            {
                max_consecutive_diff = max(max_consecutive_diff, min_bucket[i] - prev_max_element);
                prev_max_element = max_bucket[i];
            }

            // cout << "consecutive diff" << max_consecutive_diff << endl;
        }

        cout << "consecutive diff - result" << max_consecutive_diff;

        return max_consecutive_diff;
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

    int test_cases;

    cin >> test_cases;

    while (test_cases--)
    {
        vector<int> v = scan_vector<int, int>();

        cout << s.get_max_gap(v, v.size()) << endl;
    }

    return 0;
}