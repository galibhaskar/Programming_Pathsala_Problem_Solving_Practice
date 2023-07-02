#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int find_position_to_insert(vector<int> &arr, int low, int high, int key)
    {
        if (low > high)
            return low;

        int mid = (low + high) / 2;

        if (key == arr[mid])
            return mid;

        else if (key < arr[mid])
            return find_position_to_insert(arr, low, mid - 1, key);

        else
            return find_position_to_insert(arr, mid + 1, high, key);
    }
};

int main(int argc, char const *argv[])
{
    Solution s;

    vector<int> arr{1, 2, 3, 5, 6, 8, 9};

    int key;

    cin >> key;

    cout << "element can be inserted at the index:" << s.find_position_to_insert(arr, 0, arr.size() - 1, key);

    return 0;
}