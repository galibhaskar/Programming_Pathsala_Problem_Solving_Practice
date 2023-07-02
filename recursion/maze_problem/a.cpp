#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<vector<pair<int, int>>> result;

    void find_path(vector<vector<int>> &board, int n, int row, int col, vector<pair<int, int>> &path)
    {
        if (board[row][col] == 1)
            return;

        if (row == col && row == n - 1)
        {
            result.push_back(path);

            return;
        }

        if (col + 1 < n)
        {
            path.push_back({row, col + 1});

            find_path(board, n, row, col + 1, path);

            path.pop_back();
        }

        if (row + 1 < n)
        {
            path.push_back({row + 1, col});

            find_path(board, n, row + 1, col, path);

            path.pop_back();
        }
    }
};

void print_2d_vector(vector<vector<pair<int, int>>> arr)
{
    cout << "-------vector begin-----" << endl;

    for (auto ele : arr)
    {
        for (auto i : ele)
            cout << i.first << "," << i.second << "  ";
        cout << endl;
    }

    cout << "-------vector end-----" << endl;
}

int main(int argc, char const *argv[])
{
    Solution s;

    vector<vector<int>> maze = {
        {0, 0, 0, 1},
        {0, 0, 0, 0},
        {1, 0, 0, 1},
        {0, 0, 0, 0}};

    vector<pair<int, int>> path;

    path.push_back({0, 0});

    s.find_path(maze, maze.size(), 0, 0, path);

    print_2d_vector(s.result);

    return 0;
}