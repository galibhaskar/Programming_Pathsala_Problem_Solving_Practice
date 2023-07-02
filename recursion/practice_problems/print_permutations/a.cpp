#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<vector<int>> result;

    void print_permutations(vector<int> &array, int n, int index)
    {
        if (index == n)
        {
            result.push_back(array);
            return;
        }

        for (int j = index; j < n; j++)
        {
            swap(array[index], array[j]);

            print_permutations(array, n, index + 1);

            swap(array[index], array[j]);
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

    vector<int> v = {1, 2, 3};

    s.print_permutations(v, v.size(), 0);

    print_2d_vector<int>(s.result);

    return 0;
}