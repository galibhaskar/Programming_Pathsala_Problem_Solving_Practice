#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    void reverse_array(int start, int end, vector<int> &array)
    {
        if (start >= end)
            return;

        swap(array[start], array[end]);

        reverse_array(start + 1, end - 1, array);
    }

    void reverse_array_2(int start, int n, vector<int> &array)
    {
        if (start > n / 2)
            return;

        swap(array[start], array[n - start]);

        reverse_array_2(start + 1, n, array);
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
    vector<int> v = {1, 2, 3, 4, 5};

    print_vector<int>(v);

    Solution s;

    s.reverse_array(0, v.size() - 1, v);

    print_vector<int>(v);

    s.reverse_array_2(0, v.size() - 1, v);

    print_vector<int>(v);

    return 0;
}