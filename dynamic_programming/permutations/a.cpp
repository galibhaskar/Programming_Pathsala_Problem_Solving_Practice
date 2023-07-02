#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    void count_permutations(vector<char> &str, int index, int k, int n)
    {
        if (index == n)
        {
            string s(str.begin(), str.end());
            cout << s << endl;
            return;
        }

        str[index] = 'R';
        count_permutations(str, index + 1, k, n);

        if (index + k <= n)
        {
            for (int j = 0; j < k; j++)
                str[index + j] = 'W';

            count_permutations(str, index + k, k, n);
        }
    }
};

int main(int argc, char const *argv[])
{
    Solution s;

    int n, k;

    cin >> n >> k;

    vector<char> str(n);

    s.count_permutations(str, 0, k, n);
    return 0;
}