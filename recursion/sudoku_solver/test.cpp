#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool possible(vector<vector<char>> &board, int row, int col, char ch)
    {
        int row_i, col_i, row_no = row / 3, col_no = col / 3;

        for (int i = 0; i < 9; i++)
        {
            if (board[row][i] == ch)
                return false;

            if (board[i][col] == ch)
                return false;

            row_i = (row_no * 3) + (i / 3);
            col_i = (col_no * 3) + (i % 3);

            if (board[row_i][col_i] == ch)
                return false;
        }

        return true;
    }

    bool solve(vector<vector<char>> &board, int n, int row, int col)
    {
        // cout << "row:" << row << " col:" << col << endl;

        if (row == col && row == n - 1)
            return true;

        if (board[row][col] != '.')
        {
            if (col == n - 1 && solve(board, n, row + 1, 0))
                return true;

            else if (col < n - 1 && solve(board, n, row, col + 1))
                return true;
        }

        for (char ch = '1'; ch <= '9'; ch++)
        {
            // cout << "blank at row:" << row << " col:" << col
            //      << " ch:" << ch << endl;

            if (possible(board, row, col, ch))
            {
                // cout << "possible" << endl;
                board[row][col] = ch;

                if (col == n - 1 && solve(board, n, row + 1, 0))
                    return true;

                else if (col < n - 1 && solve(board, n, row, col + 1))
                    return true;

                board[row][col] = '.';
            }
        }

        return false;
    }

    void solveSudoku(vector<vector<char>> &board)
    {
        solve(board, board.size(), 0, 0);
    }
};

template <typename T>
void print_2d_vector(vector<vector<T>> arr)
{
    cout << "-------vector begin-----" << endl;

    for (auto ele : arr)
    {
        for (auto i : ele)
            cout << i << " ";
        cout << endl;
    }

    cout << "-------vector end-----" << endl;
}

int main(int argc, char const *argv[])
{
    Solution s;

    vector<vector<char>> board{
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};

    s.solveSudoku(board);

    // cout << "testing" << endl;

    print_2d_vector<char>(board);

    return 0;
}