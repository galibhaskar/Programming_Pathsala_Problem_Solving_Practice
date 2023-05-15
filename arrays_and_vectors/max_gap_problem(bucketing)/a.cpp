#include <bits/stdc++.h>

using namespace std;

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

template <typename T>
void print_vector(vector<T> arr)
{
    cout << "-------vector begin-----" << endl;

    for (auto ele : arr)
        cout << ele << " ";

    cout << "-------vector end-----" << endl;
}

int get_max_consecutive_gap(vector<int> v, int size)
{
    int min_element = INT_MAX, max_element = INT_MIN;

    for (auto i : v)
    {
        max_element = max(max_element, i);

        min_element = min(min_element, i);
    }

    cout << "min_element: " << min_element << endl;

    cout << "max_element: " << max_element << endl;

    int diff = (max_element - min_element), gap, bucket_no;

    // odd difference
    if (diff % (size - 1))
        gap = (diff / (size - 1)) + 1;

    else
        gap = (diff / (size - 1));

    // vector<vector<int>> buckets(gap + 1);

    cout << "gap: " << gap << endl;

    // int total_buckets = (diff / gap) + 1;
    int total_buckets = size;

    vector<int> buckets_min(total_buckets, INT_MAX), buckets_max(total_buckets, INT_MIN);

    for (auto element : v)
    {
        bucket_no = (element - min_element) / gap;

        buckets_min[bucket_no] = min(buckets_min[bucket_no], element);

        buckets_max[bucket_no] = max(buckets_max[bucket_no], element);

        cout << "bucket_no: " << bucket_no << endl;
    }

    print_vector<int>(buckets_max);

    print_vector<int>(buckets_min);

    int i = 1,
        j = 0;

    int max_consecutive_diff = INT_MIN;

    // while (i < total_buckets && j < total_buckets)
    // {
    //     while (buckets_min[i] == INT_MAX)
    //         i++;

    //     while (buckets_max[j] == INT_MIN)
    //         j++;

    //     cout << j << " " << buckets_max[j] << endl;

    //     cout << i << " " << buckets_max[i] << endl;

    //     max_consecutive_diff = max(max_consecutive_diff, buckets_min[i] - buckets_max[j]);

    //     cout << "max_consecutive_diff: " << max_consecutive_diff << endl;

    //     i++;

    //     j++;
    // }

    int prev_max_element = INT_MIN;

    for (int i = 0; i < size; i++)
    {
        if (buckets_min[i] == INT_MAX)
            continue;

        if (prev_max_element == INT_MIN)
            prev_max_element = buckets_max[i];

        else
        {
            max_consecutive_diff = max(max_consecutive_diff, buckets_min[i] - prev_max_element);
            prev_max_element = buckets_max[i];
        }
    }

    return max_consecutive_diff;
}

int main(int argc, char const *argv[])
{
    vector<int> v = scan_vector<int, int>();

    cout << get_max_consecutive_gap(v, v.size());

    return 0;
}