#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    void func(int i, int j, int &m, int &n, int &count, int iterator)
    {
        // cout << endl
        //      << "iterator:" << iterator << endl;
        cout << i << " " << j << endl;
        iterator++;

        // terminating condition
        if (i == m && j == n)
        {
            count++;
            cout << "-----------------------" << endl
                 << endl;
            return;
        }

        // if (i >= m || j >= n)
        // {
        //     cout << "returning " << i << " " << j << endl;
        //     return;
        // }

        // bottom move
        if (i < m)
        {
            i++;
            func(i, j, m, n, count, iterator);
        }
        else
            cout << "i execeeded-------------" << endl
                 << endl;

        // right move
        if (j < n)
        {
            j++;
            cout << iterator << ".right move with" << i << " " << j << endl
                 << endl;
            func(i, j, m, n, count, iterator);
        }
        else
            cout << "j execeeded------------" << endl
                 << endl;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;

    int i = 0, j = 0, m = 3, n = 4, count = 0, iterator = 0;

    cout << "count before:" << count << endl;

    s.func(i, j, m, n, count, iterator);

    cout << "count:" << count << endl;
    return 0;
}