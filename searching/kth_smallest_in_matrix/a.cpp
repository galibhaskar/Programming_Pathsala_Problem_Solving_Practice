#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int find_count_in_sorted_array(vector<int> &arr, int x)
    {
        return (upper_bound(arr.begin(), arr.end(), x) - arr.begin());
    }

    int count(vector<vector<int>> &arr, int x)
    {
        int x_count = 0;

        for (int i = 0; i < arr.size(); i++)
            x_count += find_count_in_sorted_array(arr[i], x);

        return x_count;
    }

    int kth_smallest_in_2dmatrix(vector<vector<int>> &arr, int k)
    {
        int low = INT_MAX, high = INT_MIN, mid;

        // finding min and max elements for low and high
        // assuming each row is sorted
        for (int i = 0; i < arr.size(); i++)
        {
            low = min(low, arr[i][0]);
            high = max(high, arr[i][arr.size() - 1]);
        }

        while (low <= high)
        {
            mid = low + ((high - low) / 2);

            if (count(arr, mid) < k)
                low = mid + 1;

            else
            {
                if (count(arr, mid - 1) < k)
                    return mid;

                high = mid - 1;
            }
        }
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    int k, num, n;

    cin >> n;

    vector<vector<int>> arr(n, vector<int>(n));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> num;
            arr[i][j] = num;
        }
    }

    cin >> k;

    cout << s.kth_smallest_in_2dmatrix(arr, k);

    return 0;
}