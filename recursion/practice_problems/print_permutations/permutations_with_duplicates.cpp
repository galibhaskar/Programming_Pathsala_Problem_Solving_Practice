#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<string> result;

    void print_permutations(string &arr, int n, int index)
    {
        if (index == n)
        {
            result.push_back(arr);
            return;
        }

        vector<bool> freq(26, 0);

        for (int j = index; j < n; j++)
        {
            if (freq[arr[j] - 'a'] == 0)
            {
                swap(arr[index], arr[j]);

                print_permutations(arr, n, index + 1);

                swap(arr[index], arr[j]);

                freq[arr[j] - 'a'] = 1;
            }
        }
    }
};

template <typename T>
void print_vector(vector<T> arr)
{
    cout << "-------vector begin-----" << endl;

    for (auto ele : arr)
        cout << ele << " ";

    cout << endl
         << "-------vector end-----" << endl;
}

int main(int argc, char const *argv[])
{
    Solution s;

    string arr = "aba";

    s.print_permutations(arr, arr.length(), 0);

    print_vector<string>(s.result);

    return 0;
}