#include <bits/stdc++.h>

using namespace std;

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
    void rotate_k_times(vector<int> &arr, int k)
    {
        reverse(arr.begin(), arr.begin() + k);

        reverse(arr.begin() + k + 1, arr.end());

        reverse(arr.begin(), arr.end());
    }

    void left_rotate(vector<int> &arr, int k)
    {
        // cout << "k" << k << endl;
        // cout << "arr before rotation" << endl;
        // print_vector<int>(arr);
        // cout << "arr before rotation" << endl;

        if (k >= arr.size())
            k %= arr.size();

        if (k == 0)
            return;

        rotate_k_times(arr, k);
    }

    void right_rotate(vector<int> &arr, int k)
    {
        left_rotate(arr, arr.size() - k);
    }
};

int main(int argc, char const *argv[])
{
    Solution s;

    vector<int> v{1, 2, 3, 4}, v1{1, 2, 3, 4};

    int k;

    cin >> k;

    s.left_rotate(v, k);

    print_vector<int>(v);

    s.right_rotate(v1, k);

    print_vector<int>(v1);

    return 0;
}