#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int j = matrix[0].size() - 1, i = 0;

        while (i < matrix.size() && j >= 0)
        {
            if (matrix[i][j] == target)
                return true;

            else if (matrix[i][j] > target)
                j--;

            else
                i++;
        }

        return false;
    }
};

template <typename T, typename size_type>
vector<vector<T>> scan_2d_vector(size_type row_count = 0, size_type col_count = 0)
{
    size_type m, n, i = 0, j;

    if (row_count == 0 || col_count == 0)
        cin >> m >> n;

    else
    {
        m = row_count;
        n = col_count;
    }

    vector<vector<T>> arr(m, vector<T>(n));

    for (auto i = 0; i < m; i++)
        for (auto j = 0; j < n; j++)
            cin >> arr[i][j];

    return arr;
}

int main(int argc, char const *argv[])
{
    Solution s;

    vector<vector<int>> v = scan_2d_vector<int, int>();

    int target;

    cin >> target;

    cout << s.searchMatrix(v, target);

    return 0;
}
