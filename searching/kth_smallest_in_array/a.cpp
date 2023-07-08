#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int count(vector<int> &arr, int x)
    {
        int count_value = 0;

        for (int i = 0; i < arr.size(); i++)
            if (arr[i] <= x)
                count_value++;

        return count_value;
    }

    int kth_smallest_element(vector<int> &arr, int k)
    {
        int low = INT_MAX, high = INT_MIN, mid;

        // finding low(min element) and high(max element)
        for (int i = 0; i < arr.size(); i++)
        {
            low = min(low, arr[i]);
            high = max(high, arr[i]);
        }

        while (low <= high)
        {
            mid = low + ((high - low) / 2);

            // cout << "low:" << low << " high:" << high << endl;

            // cout << "mid:" << mid << endl
            //      << count(arr, mid) << " k:" << k << endl;

            if (count(arr, mid) < k)
                low = mid + 1;

            else
            {
                if (count(arr, mid - 1) < k)
                    return mid;

                else
                    high = mid - 1;
            }
        }
    }
};

int main(int argc, char const *argv[])
{
    Solution s;

    vector<int> arr;

    int k, n, num;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> num;

        arr.push_back(num);
    }

    cin >> k;

    cout << s.kth_smallest_element(arr, k);

    return 0;
}