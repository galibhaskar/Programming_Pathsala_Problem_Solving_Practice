#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool possible(vector<vector<char>> &board, char c, int sudoku_box_size, int row, int col)
    {
        int row_index, col_index;

        for (int i = 0; i < sudoku_box_size * sudoku_box_size; i++)
        {
            // checking the col
            if (board[i][col] == c)
                return false;

            // checking the row
            if (board[row][i] == c)
                return false;

            row_index = sudoku_box_size * (row / sudoku_box_size) + (i / sudoku_box_size);

            col_index = sudoku_box_size * (col / sudoku_box_size) + (i % sudoku_box_size);

            if (board[row_index][col_index] == c)
                return false;
        }

        return true;
    }

    bool solve(vector<vector<char>> &board, int sudoku_box_size)
    {
        for (int row = 0; row < board.size(); row++)
        {
            for (int col = 0; col < board[0].size(); col++)
            {
                if (board[row][col] == '.')
                {
                    for (char ch = '1'; ch <= '9'; ch++)
                    {
                        if (possible(board, ch, sudoku_box_size, row, col))
                        {
                            board[row][col] = ch;

                            if (solve(board, sudoku_box_size) == true)
                                return true;

                            board[row][col] = '.';
                        }
                    }
                }
            }
        }

        return true;
    }

    void solve_Sudoku(vector<vector<char>> &board, int box_size)
    {
        solve(board, box_size);
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

    int box_size = 3;

    vector<vector<char>> board{
        {'5', '3', '.', '6', '7', '8', '9', '1', '2'},
        {'6', '7', '2', '1', '9', '5', '3', '4', '8'},
        {'.', '9', '8', '3', '4', '2', '5', '6', '7'},

        {'8', '5', '9', '7', '6', '1', '4', '2', '3'},
        {'4', '2', '6', '8', '5', '3', '7', '9', '1'},
        {'7', '1', '3', '9', '.', '4', '8', '.', '6'},

        {'9', '6', '.', '5', '3', '7', '2', '8', '4'},
        {'2', '8', '7', '4', '1', '9', '6', '3', '5'},
        {'3', '4', '5', '2', '8', '6', '1', '7', '9'},
    };

    s.solve_Sudoku(board, 3);

    print_2d_vector<char>(board);

    return 0;
}