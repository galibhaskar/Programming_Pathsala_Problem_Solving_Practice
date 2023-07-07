#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int binary_search(vector<vector<int>> &arr, int target, int low, int high,
                      int m, int n, bool row_based, int row_index)
    {
        int mid;

        while (low <= high)
        {
            mid = low + ((high - low) / 2);

            if (row_based)
            {
                if (arr[mid][0] <= target && target <= arr[mid][n - 1])
                    return binary_search(arr, target, 0, n - 1, m, n, false, mid);

                else if (arr[mid][0] > target)
                    high = mid - 1;

                else
                    low = mid + 1;
            }

            else
            {
                if (arr[row_index][mid] == target)
                    return true;

                else if (arr[row_index][mid] < target)
                    low = mid + 1;

                else
                    high = mid - 1;
            }
        }

        return false;
    }

    bool search_in_2d_array(vector<vector<int>> &arr, int target)
    {
        return binary_search(arr, target, 0, arr.size() - 1, arr.size(), arr[0].size(), true, 0);
    }
};

int main(int argc, char const *argv[])
{
    Solution s;

    int m, n, num, test_cases, target;

    cin >> m >> n;

    vector<vector<int>> arr(m, vector<int>(n));

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> num;

            arr[i][j] = num;
        }
    }

    cin >> test_cases;

    while (test_cases--)
    {
        cin >> target;

        cout << (s.search_in_2d_array(arr, target) ? "true" : "false") << endl;
    }

    return 0;
}