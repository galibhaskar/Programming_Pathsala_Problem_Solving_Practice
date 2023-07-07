#include <bits/stdc++.h>

using namespace std;

class MountainArray
{
public:
    int get(int index);
    int length();
};

class Solution
{
public:
    int get_peak_index(MountainArray &arr)
    {
        int low = 0, high = arr.length(), mid;

        while (low <= high)
        {
            mid = low + ((high - low) / 2);

            cout << "mid:" << mid << " ---" << arr.get(mid) << endl;

            if (mid == 0 && arr.get(mid + 1) > arr.get(mid))
                return mid + 1;

            else if (mid == arr.length() - 1 && arr.get(mid - 1) > arr.get(mid))
                return mid - 1;

            else if ((arr.get(mid) > arr.get(mid + 1)) && (arr.get(mid) > arr.get(mid - 1)))
                return mid;

            else if (arr.get(mid + 1) > arr.get(mid))
                low = mid + 1;

            else
                high = mid - 1;
        }

        return -1;
    }

    int binary_search(MountainArray &arr, int low, int high, int target, bool reverse_sort)
    {
        int mid;

        // cout<<"binary search for:"<<low<<" "<<high<<endl;
        if (low == high)
            return arr.get(low) == target ? low : -1;

        while (low <= high)
        {
            mid = low + ((high - low) / 2);

            // cout<<"ele:"<<arr.get(mid)<<" target:"<<target<<endl;

            if (arr.get(mid) == target)
                return mid;

            if (reverse_sort)
            {
                if (arr.get(mid) > target)
                    low = mid + 1;

                else
                    high = mid - 1;
            }
            else
            {
                if (arr.get(mid) < target)
                    low = mid + 1;

                else
                    high = mid - 1;
            }
        }

        return -1;
    }

    int findInMountainArray(int target, MountainArray &mountainArr)
    {
        int peak_index = get_peak_index(mountainArr);

        cout << " peak index:" << peak_index << endl
             << "target:" << target << endl;

        if (mountainArr.get(peak_index) == target)
            return peak_index;

        int min_index = binary_search(mountainArr, 0, peak_index - 1, target, false);

        if (min_index != -1)
            return min_index;

        else
            return binary_search(mountainArr, peak_index + 1, mountainArr.length() - 1, target, true);
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    // s.get_peak_index();
    return 0;
}