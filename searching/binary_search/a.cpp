#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int binary_search(vector<int> &arr, int low, int high, int key)
    {
        if (low > high)
            return -1;

        int mid = (low + high) / 2;

        if (key == arr[mid])
            return mid;

        else if (key < arr[mid])
            return binary_search(arr, low, mid - 1, key);

        else
            return binary_search(arr, mid + 1, high, key);
    }
};

int main(int argc, char const *argv[])
{
    Solution s;

    vector<int> arr{1, 2, 3, 5, 6, 8, 9};

    int key;

    cin >> key;

    cout << "found at index:" << s.binary_search(arr, 0, arr.size() - 1, key);

    return 0;
}