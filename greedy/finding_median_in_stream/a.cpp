#include <bits/stdc++.h>

using namespace std;

class Solution
{
    double current_median;

    // maintain to heaps, one is max heap and min heap
    // maintain a variable to keep track of current median
    // based on the current median updates the heaps

    // max heap(by default)
    priority_queue<int> left_half;

    // min heap
    priority_queue<int, vector<int>, greater<int>> right_half;

    // left half -> max heap
    // right half -> min heap

public:
    Solution()
    {
        current_median = 0;
    }

    void insert_num(int num)
    {

        // checking whether the left and right heaps are same length or not
        if (left_half.size() == right_half.size())
        {
            cout << "case-1:   left half == right half" << endl;

            // insert in left half
            if (num <= current_median)
            {
                left_half.push(num);

                cout << "num less than cm" << endl;

                // update the median
                current_median = left_half.top();
            }

            // insert in right half
            else
            {
                cout << "num greater than cm" << endl;

                right_half.push(num);

                // update the median
                current_median = right_half.top();
            }
        }

        // right half is larger
        else if (left_half.size() < right_half.size())
        {
            cout << "case-2:   left half < right half" << endl;

            // insert in right half but move the right half top element to left half
            if (num > current_median)
            {
                cout << "num greater than cm" << endl;

                left_half.push(right_half.top());

                right_half.pop();

                right_half.push(num);
            }

            else
                left_half.push(num);

            // update the current median
            current_median = ((left_half.top() + right_half.top()) * 1.0) / 2;
        }

        // left half is larger
        else
        {
            cout << "case-3:   left half > right half" << endl;

            // insert in left half but move the top element to right half
            if (num <= current_median)
            {
                cout << "num less than cm" << endl;

                right_half.push(left_half.top());

                left_half.pop();

                left_half.push(num);
            }

            else
                right_half.push(num);

            // update the current median
            current_median = ((left_half.top() + right_half.top()) * 1.0) / 2;
        }
    }

    double get_median()
    {
        return current_median;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;

    cout << s.get_median() << endl;

    int num;

    cin >> num;

    while (num != 0)
    {
        s.insert_num(num);

        cout << "current median:" << s.get_median() << endl;

        cin >> num;
    }

    return 0;
}