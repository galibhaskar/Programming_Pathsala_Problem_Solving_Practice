#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    void lexicographic_subsets(int *arr, int n, int index, int *result, int res_index)
    {
        for (int i = 0; i < res_index; i++)
            cout << result[i];

        cout << endl;

        if (index == n)
            return;

        for (int j = index; j < n; j++)
        {
            result[res_index] = arr[j];

            lexicographic_subsets(arr, n, j + 1, result, res_index + 1);
        }
    }
};

int main(int argc, char const *argv[])
{
    Solution s;

    int n = 4;

    int *arr = new int[n]{1, 2, 3, 4};

    int *result = new int[n];

    s.lexicographic_subsets(arr, n, 0, result, 0);

    return 0;
}