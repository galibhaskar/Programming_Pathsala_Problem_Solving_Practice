#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool valid_subsets(vector<int> &arr, int k, int X)
    {
        int sum = 0;

        for (int i = 0; i < k; i++)
            sum += arr[i];

        if (sum > X)
            return false;

        for (int i = k; i < arr.size(); i++)
        {
            sum -= arr[i - k];
            sum += arr[i];

            if (sum > X)
                return false;
        }

        return true;
    }

    int maximize_k_subset_sum(vector<int> &arr, int X)
    {
        int low = 0, high = arr.size() - 1, mid;

        while (low <= high)
        {
            mid = low + ((high - low) / 2);

            if (!valid_subsets(arr, mid, X))
                high = mid - 1;

            else
            {
                if (mid == arr.size() || !valid_subsets(arr, mid + 1, X))
                    return mid;

                low = mid + 1;
            }
        }
    }
};

int main(int argc, char const *argv[])
{
    Solution s;

    vector<int> arr{1, 2, 3, 4};

    int X;

    cin >> X;

    cout << s.maximize_k_subset_sum(arr, X);

    return 0;
}