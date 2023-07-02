#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int count = 0;

    void subset_sum(int *arr, int n, int sum, int index)
    {
        if (sum <= 0 || index == n)
        {
            if (sum == 0)
                count++;

            return;
        }

        subset_sum(arr, n, sum - arr[index], index);

        subset_sum(arr, n, sum - arr[index], index + 1);
    }
};

int main(int argc, char const *argv[])
{
    Solution s;

    int n = 2;

    int *arr = new int[n]{1, 2};

    int sum;

    cin >> sum;

    // int *result = new int[n];

    s.subset_sum(arr, n, sum, 0);

    cout << "count:" << s.count << endl;
    return 0;
}