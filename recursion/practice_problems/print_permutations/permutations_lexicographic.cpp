#include <bits/stdc++.h>

using namespace std;

// assuming the arr doesn't have duplicates and in sorted order.

template <typename T>
void print_vector(vector<T> arr)
{
    cout << "-------vector begin-----" << endl;

    for (auto ele : arr)
        cout << ele << " ";

    cout << "-------vector end-----" << endl;
}

class Solution
{
public:
    vector<vector<int>> result;

    void rotate_k_times(vector<int> &arr, int start_index, int end_index, int k)
    {
        reverse(arr.begin() + start_index, arr.begin() + start_index + k);

        reverse(arr.begin() + start_index + k, arr.begin() + end_index + 1);

        reverse(arr.begin() + start_index, arr.begin() + end_index + 1);
    }

    void left_rotate(vector<int> &arr, int start_index, int end_index, int k)
    {
        if (k > arr.size())
            k %= arr.size();

        if (k == 0)
            return;

        rotate_k_times(arr, start_index, end_index, k);
    }

    void right_rotate(vector<int> &arr, int start_index, int end_index, int k)
    {
        // cout << "left rotate:"
        //      << (end_index - start_index + 1) - k << "times"
        //      << "start_index:" << start_index
        //      << " end_index:" << end_index << endl;

        left_rotate(arr, start_index, end_index, (end_index - start_index + 1) - k);
    }

    void print_permutations_lexicographic(vector<int> &arr, int index)
    {
        if (index == arr.size() - 1)
        {
            result.push_back(arr);
            return;
        }

        for (int j = index; j < arr.size(); j++)
        {
            // cout << endl
            //      << "index:" << index
            //      << " j:" << j << endl;
            right_rotate(arr, index, j, 1);

            // print_vector<int>(arr);

            print_permutations_lexicographic(arr, index + 1);

            // cout << endl
            //      << "==========continued"
            //      << "index:" << index
            //      << " j:" << j << endl;

            left_rotate(arr, index, j, 1);

            // print_vector<int>(arr);
        }
    }
};

template <typename T>
void print_2d_vector(vector<vector<T>> arr)
{
    cout << "-------vector begin-----" << endl;

    for (auto ele : arr)
    {
        for (auto i : ele)
            cout << i << " ";
        cout << endl;
    }

    cout << "-------vector end-----" << endl;
}

int main(int argc, char const *argv[])
{
    Solution s;

    vector<int> v{1, 2, 3, 4};

    s.print_permutations_lexicographic(v, 0);

    print_2d_vector<int>(s.result);

    return 0;
}