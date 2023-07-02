#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int find_max(int *arr, int start, int end)
    {
        if (start == end)
            return arr[start];

        int mid = (start + (end - start) / 2);

        return max(find_max(arr, start, mid), find_max(arr, mid + 1, end));
    }
};

int main(int argc, char const *argv[])
{
    Solution s;

    int *arr = new int[5]{1, 12, 53, 47, 321};

    cout << "max element:" << s.find_max(arr, 0, 5);

    return 0;
}