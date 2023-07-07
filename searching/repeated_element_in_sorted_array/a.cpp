#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int find_repeated_element(vector<int> &arr)
    {
        int low = 0, high = arr.size(), mid;

        while (low <= high)
        {
            mid = low + ((high - low) / 2);

            if (mid + 1 < arr.size() && arr[mid] == arr[mid + 1])
                return arr[mid];

            else if (arr[mid] == mid)
                low = mid + 1;

            else
                high = mid - 1;
        }
    }
};

int main(int argc, char const *argv[])
{
    Solution s;

    vector<int> arr{0, 1, 2, 3, 3, 4, 5, 6};

    cout << s.find_repeated_element(arr);

    return 0;
}