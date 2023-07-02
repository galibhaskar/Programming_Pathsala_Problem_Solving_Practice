#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int first_occurence(vector<int> &arr, int key, int low, int high)
    {
        // cout << "first occurence:"
        //      << "low:" << low << " high" << high << endl;

        if (low > high)
            return low;

        int mid = (low + high) / 2;

        if (key < arr[mid])
            return first_occurence(arr, key, low, mid - 1);

        else if (key > arr[mid])
            return first_occurence(arr, key, mid + 1, high);

        else
        {
            if (mid <= 0)
                return 0;

            else if ((mid - 1 >= 0) && arr[mid - 1] != key)
                return mid;

            else
                return first_occurence(arr, key, low, mid - 1);
        }
    }

    int last_occurence(vector<int> &arr, int key, int low, int high)
    {
        // cout << "last occurence:"
        //      << "low:" << low << " high" << high << endl;

        if (low > high)
            return low;

        int mid = (low + high) / 2;

        if (key < arr[mid])
            return last_occurence(arr, key, low, mid - 1);

        else if (key > arr[mid])
            return last_occurence(arr, key, mid + 1, high);

        else
        {
            if (mid >= arr.size() - 1)
                return arr.size();

            else if ((mid + 1 < arr.size()) && arr[mid + 1] != key)
                return mid;

            else
                return last_occurence(arr, key, mid + 1, high);
        }
    }

    int count_frequency_of_element_in_sorted_array(vector<int> &arr, int key)
    {
        int last_index = last_occurence(arr, key, 0, arr.size() - 1),
            first_index = first_occurence(arr, key, 0, arr.size() - 1);

        if (first_index == last_index)
        {
            if (arr[first_index] == key)
                return 1;
            return 0;
        }

        return last_index - first_index + 1;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;

    vector<int> arr{1, 2, 2, 3, 3, 5, 6, 7, 7, 7, 7, 7, 7, 7, 8, 9};

    int key;

    cin >> key;

    cout << "frequency of the element:"
         << s.count_frequency_of_element_in_sorted_array(arr, key);

    return 0;
}