#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int get_pivot_index(vector<int> &arr)
    {
        int low = 0, high = arr.size(), pivot_index;

        while (low <= high)
        {
            pivot_index = low + (high - low) / 2;

            if (pivot_index + 1 < arr.size() && arr[pivot_index] > arr[pivot_index + 1])
                return pivot_index;

            else if (arr[pivot_index] <= arr[arr.size() - 1])
                high = pivot_index - 1;

            else
                low = pivot_index + 1;
        }

        return -1;
    }

    int apply_binary_search(vector<int> &arr, int low, int high, int search_key)
    {
        if (low > high)
            return -1;

        int mid = low + (high - low) / 2;

        if (arr[mid] == search_key)
            return mid;

        else if (arr[mid] < search_key)
            return apply_binary_search(arr, mid + 1, high, search_key);

        else
            return apply_binary_search(arr, low, mid - 1, search_key);
    }

    int search_in_sorted_array(vector<int> &arr, int search_key)
    {
        int pivot_index = get_pivot_index(arr);

        cout << pivot_index << endl;

        if (search_key <= arr[arr.size() - 1])
            return apply_binary_search(arr, pivot_index + 1, arr.size() - 1, search_key);

        else
            return apply_binary_search(arr, 0, pivot_index, search_key);
    }
};

int main(int argc, char const *argv[])
{
    Solution s;

    vector<int> arr{1, 2, 3, 4, 5, 6, 7};
    // vector<int> arr{5, 6, 7, 1, 2, 3, 4};

    int key;
    cin >> key;

    cout << s.search_in_sorted_array(arr, key);

    return 0;
}