#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<vector<string>> result;

    bool is_palindrome(string s)
    {
        int n = s.length(), i = 0;

        while (i < (n / 2))
        {
            if (s[i] != s[n - i - 1])
                return false;

            i++;
        }

        return true;
    }

    void get_palindrome_strings(string s, vector<string> path, int index)
    {
        if (index == s.length())
        {
            result.push_back(path);
            return;
        }

        for (int j = index; j < s.length(); j++)
        {
            if (is_palindrome(s.substr(index, j - index + 1)))
            {
                path.push_back(s.substr(index, (j - index + 1)));

                get_palindrome_strings(s, path, j + 1);

                path.pop_back();
            }
        }
    }

    vector<vector<string>> palidrome_partitioning(string s)
    {
        vector<string> path;

        get_palindrome_strings(s, path, 0);

        return result;
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

    string str;

    cin >> str;

    print_2d_vector<string>(s.palidrome_partitioning(str));

    return 0;
}