#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    void pushBottom(int element, stack<int> &s)
    {
        if (s.empty())
        {
            s.push(element);

            return;
        }

        int temp_element = s.top();

        s.pop();

        pushBottom(element, s);

        s.push(temp_element);
    }
};

void printStack(stack<int> s)
{
    while (!s.empty())
    {
        cout << s.top() << endl;
        s.pop();
    }
}

void pushElements(stack<int> &s, vector<int> arr)
{
    for (auto i : arr)
        s.push(i);

    cout << s.top() << endl;
}

int main(int argc, char const *argv[])
{
    Solution s;

    stack<int> stk;

    pushElements(stk, {4, 3, 2, 1});

    s.pushBottom(5, stk);

    printStack(stk);

    return 0;
}