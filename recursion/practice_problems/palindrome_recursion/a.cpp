#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool palindrome(int start, int n, vector<int> &array)
    {
        if (start >= n / 2)
            return true;

        if (array[start] != array[n - start - 1])
            return false;

        palindrome(start + 1, n, array);
    }
};

int main(int argc, char const *argv[])
{
    vector<int> v = {1, 2, 1};

    Solution s;

    cout << (s.palindrome(0, v.size(), v) ? "Palindrome" : "Not a Palindrome");

    return 0;
}