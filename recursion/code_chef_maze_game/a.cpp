#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void print_vector(vector<char> &path)
{
    for (auto i : path)
        cout << i;

    cout << " ";
}

void find_path(vector<vector<int>> &matrix,
               int row, int col, vector<char> &path)
{
    if (row == col && row == matrix.size() - 1)
    {
        print_vector(path);
        return;
    }

    // marking the path as visited
    matrix[row][col] = -1;

    // cout << "row:" << row << " col:" << col << endl;

    // cout << "path:" << endl;

    // print_vector(path);

    // down
    if (row + 1 < matrix.size() && matrix[row + 1][col] > 0)
    {
        path.push_back('D');
        find_path(matrix, row + 1, col, path);
        path.pop_back();
    }

    // left
    if (col - 1 >= 0 && matrix[row][col - 1] > 0)
    {
        path.push_back('L');
        find_path(matrix, row, col - 1, path);
        path.pop_back();
    }

    // right
    if (col + 1 < matrix.size() && matrix[row][col + 1] > 0)
    {
        path.push_back('R');
        find_path(matrix, row, col + 1, path);
        path.pop_back();
    }

    // top
    if (row - 1 >= 0 && matrix[row - 1][col] > 0)
    {
        path.push_back('T');
        find_path(matrix, row - 1, col, path);
        path.pop_back();
    }

    matrix[row][col] = 1;
}

int main()
{
    // your code goes here
    int test_cases, n;

    cin >> test_cases;

    while (test_cases--)
    {
        cin >> n;

        vector<vector<int>> matrix(n, vector<int>(n));

        vector<char> path;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> matrix[i][j];
            }
        }

        find_path(matrix, 0, 0, path);

        cout << endl;
    }

    return 0;
}
