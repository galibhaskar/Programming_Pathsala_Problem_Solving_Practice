#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int count = 0;

    void print_array(int *arr, int size)
    {
        cout << endl;

        for (int i = 0; i < size; i++)
            cout << arr[i] << " ";

        cout << endl;
    }

    template <typename T>
    void print_vector(vector<T> arr)
    {
        // cout << "-------vector begin-----" << endl;

        for (auto ele : arr)
            cout << ele << " ";

        // cout << "-------vector end-----" << endl;
    }

    void printSubsets(int *arr, int *result, int index, int length_of_result, int N)
    {
        // cout << "index:" << index
        //      << " length of result:" << length_of_result
        //      << " N:" << N << endl;

        if (index == N)
        {
            print_array(result, length_of_result);
            count++;
            return;
        }

        // for Y
        result[length_of_result] = arr[index];
        printSubsets(arr, result, index + 1, length_of_result + 1, N);

        // for N
        printSubsets(arr, result, index + 1, length_of_result, N);
    }

    void get_binary(int *arr, vector<int> &result, int j, int num)
    {
        if (num == 0)
            return;

        get_binary(arr, result, j - 1, num / 2);

        if (num % 2)
            result.push_back(arr[j]);
    }

    void print_subsets_using_bit_masking(int *arr, int size)
    {
        vector<int> result;

        cout << "pow(2, size):" << pow(2, size) << endl;

        for (int i = 0; i < pow(2, size); i++)
        {
            cout << "subset with i:" << i << endl;

            get_binary(arr, result, size - 1, i);

            // cout << "dsfasdf" << endl;
            print_vector<int>(result);

            result.clear();
        }
    }
};

int main(int argc, char const *argv[])
{
    int value_count = 3;
    int *arr = new int[value_count]{1, 2, 3};

    int *result = new int[value_count];

    Solution *s = new Solution();

    s->printSubsets(arr, result, 0, 0, value_count);

    cout << "No of subsets" << s->count << endl;

    s->print_subsets_using_bit_masking(arr, value_count);

    return 0;
}