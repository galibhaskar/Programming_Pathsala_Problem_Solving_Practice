#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    void merge(vector<int> &array, int start, int mid, int end)
    {
        vector<int> temp;

        int left_array_index = start, right_array_index = mid + 1;

        while (left_array_index <= mid && right_array_index <= end)
        {
            if (array[left_array_index] <= array[right_array_index])
                temp.push_back(array[left_array_index++]);

            else
                temp.push_back(array[right_array_index++]);
        }

        while (left_array_index <= mid)
            temp.push_back(array[left_array_index++]);

        while (right_array_index <= end)
            temp.push_back(array[right_array_index++]);

        for (int i = start; i <= end; i++)
            array[i] = temp[i - start];
    }

    void merge_sort(vector<int> &array, int start, int end)
    {
        if (start == end)
            return;

        int mid = (start + (end - start) / 2);

        merge_sort(array, start, mid);

        merge_sort(array, mid + 1, end);

        merge(array, start, mid, end);
    }
};

template <typename T>
void print_vector(vector<T> arr)
{
    cout << "-------vector begin-----" << endl;

    for (auto ele : arr)
        cout << ele << " ";

    cout << "-------vector end-----" << endl;
}

int main(int argc, char const *argv[])
{

    vector<int> v = {1, 5, 6, 1, 25, 7, 2, 57, 1, 2};

    print_vector<int>(v);

    Solution s;

    s.merge_sort(v, 0, v.size() - 1);

    print_vector<int>(v);

    return 0;
}