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

        int temp = s.top();

        s.pop();

        pushBottom(element, s);

        s.push(temp);
    }

    void reverseStack(stack<int> &s)
    {
        if (s.empty())
            return;

        int element = s.top();

        s.pop();

        reverseStack(s);

        pushBottom(element, s);
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
}

int main(int argc, char const *argv[])
{
    Solution s;

    stack<int> stk;

    pushElements(stk, {1,2,3,4,5});

    s.reverseStack(stk);

    printStack(stk);

    return 0;
}