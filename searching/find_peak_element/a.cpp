#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int find_peak_element(vector<int> &arr)
    {
        int low = 0, high = arr.size(), mid;

        while (low <= high)
        {
            mid = low + ((high - low) / 2);

            if ((mid == 0 && arr[mid] >= arr[mid + 1]) ||
                (mid == arr.size() - 1 && arr[mid] >= arr[mid - 1]))
                return arr[mid];

            else if (arr[mid] >= arr[mid + 1] && arr[mid] >= arr[mid - 1])
                return arr[mid];

            // moving towards greater value
            else if (arr[mid] < arr[mid + 1])
                low = mid + 1;

            else
                high = mid - 1;
        }

        return -1;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;

    vector<int> arr{10, 20, 15, 2, 23, 90, 67};

    cout << s.find_peak_element(arr);

    return 0;
}