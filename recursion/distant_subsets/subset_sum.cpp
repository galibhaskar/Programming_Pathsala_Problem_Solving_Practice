#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int count = 0;

    void subset_sum(int *arr, int n, int index, int sum)
    {
        // should not terminate when sum is equal to 0
        // array might contain zero's or negative numbers
        // if (sum == 0)
        // {
        //     count++;
        //     return;
        // }

        // if (sum < 0 || index == n)
        //     return;

        // cout << "index:" << index << " sum:" << sum << endl;


        // in lexicographic approach, subsets can be in leaf and non-lead nodes
        // in Y or N approach, all the subsets will be in leaf nodes.
        
        // leaf node decision
        if (index == n && sum == 0)
        {
            count++;

            return;
        }

        // non-leaf node
        if (sum == 0)
            count++;

        for (int j = index; j < n; j++)
        {
            subset_sum(arr, n, j + 1, sum - arr[j]);
        }
    }

    int subset_sum_version_2(int *arr, int n, int index, int sum)
    {
        // should not terminate when sum is equal to 0
        // array might contain zero's or negative numbers
        // if (sum == 0)
        //     return 1;

        // if (sum < 0 || index == n)
        //     return 0;

        if (index == n)
        {
            return sum == 0;
        }

        // Yes + No
        return subset_sum_version_2(arr, n, index + 1, sum - arr[index]) +
               subset_sum_version_2(arr, n, index + 1, sum);
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

    s.subset_sum(arr, n, 0, sum);

    cout << "count:" << s.count << endl;

    cout << "count:" << s.subset_sum_version_2(arr, n, 0, sum);

    return 0;
}