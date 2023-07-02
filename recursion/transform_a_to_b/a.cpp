// Problem: https://codeforces.com/contest/727/problem/A

#include <bits/stdc++.h>

using namespace std;

class Solution
{

public:
    vector<int> steps;

    void reduce(int &a, int &num)
    {
        if (num <= a)
        {
            steps.push_back(num);

            return;
        }

        // step-1
        if (num % 2 == 0)
        {
            steps.push_back(num);

            num /= 2;
        }

        // step-2
        else if ((num - 1) % 10 == 0)
        {
            steps.push_back(num);

            num = ((num - 1) / 10);
        }

        else
        {
            return;
        }

        reduce(a, num);
    }
};

template <typename T>
void print_vector_in_reverse(vector<T> arr)
{
    for (auto it = arr.rbegin(); it != arr.rend(); it++)
        cout << *it << " ";
}

int main(int argc, char const *argv[])
{
    Solution s;

    int a, b;

    cin >> a >> b;

    s.reduce(a, b);

    if (a == b)
    {
        cout << "YES" << endl
             << s.steps.size() << endl;

        print_vector_in_reverse<int>(s.steps);
    }

    else
        cout << "NO" << endl;

    return 0;
}