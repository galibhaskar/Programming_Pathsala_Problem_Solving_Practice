#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int space_optimization(string s1, string s2)
    {
        vector<int> arr1(s2.length() + 1, 0), arr2(s2.length() + 1, 0);

        for (int i = 1; i < s1.length() + 1; i++)
        {
            for (int j = 1; j < s2.length() + 1; j++)
            {
                if (s1[i - 1] == s2[j - 1])
                    arr2[j] = 1 + arr1[j - 1];

                else
                    arr2[j] = max(arr2[j - 1], arr1[j]);
            }

            arr1 = arr2;
        }

        return arr1[s2.length()];
    }
};

int main(int argc, char const *argv[])
{
    Solution s;

    string s1, s2;

    cin >> s1 >> s2;

    cout << s.space_optimization(s1, s2);

    return 0;
}