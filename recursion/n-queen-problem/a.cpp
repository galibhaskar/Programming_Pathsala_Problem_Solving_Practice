#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<vector<string>> result;

    bool isSafe(int row, int col, int n, vector<string> &board)
    {
        // cout << "checking-row:" << row << " col:" << col << endl;

        int temp_row = row, temp_col = col;

        // left direction
        while (temp_col >= 0)
        {
            if (board[temp_row][temp_col] == 'Q')
                return false;

            temp_col--;
        }

        temp_row = row;
        temp_col = col;
        // top-left direction
        while (temp_row >= 0 && temp_col >= 0)
        {
            if (board[temp_row][temp_col] == 'Q')
                return false;

            temp_row--;
            temp_col--;
        }

        temp_row = row;
        temp_col = col;
        // bottom-left direction
        while (temp_row < n && temp_col >= 0)
        {
            if (board[temp_row][temp_col] == 'Q')
                return false;

            temp_row++;
            temp_col--;
        }

        return true;
    }

    void n_queens(int col, int n, vector<string> &board)
    {
        if (col == n)
        {
            for (auto i : board)
                cout << i << endl;

            cout << endl;

            result.push_back(board);
            return;
        }

        for (int row_index = 0; row_index < n; row_index++)
        {
            if (isSafe(row_index, col, n, board))
            {
                // cout << "safe - row:" << row_index << " col:" << col << endl;

                board[row_index][col] = 'Q';

                n_queens(col + 1, n, board);

                board[row_index][col] = '.';
            }
        }
    }

    void n_queens_optimal(int col, int n,
                          vector<string> &board,
                          vector<bool> &upper_diag,
                          vector<bool> &lower_diag,
                          vector<bool> &queens_placed)
    {
        if (col == n)
        {
            for (auto i : board)
                cout << i << endl;

            cout << endl;

            result.push_back(board);
            return;
        }

        for (int row_i = 0; row_i < n; row_i++)
        {
            if (!queens_placed[row_i] &&
                !upper_diag[n - 1 + col - row_i] &&
                !lower_diag[row_i + col])
            {
                board[row_i][col] = 'Q';

                queens_placed[row_i] = 1;

                upper_diag[n - 1 + col - row_i] = 1;

                lower_diag[row_i + col] = 1;

                n_queens_optimal(col + 1, n, board, upper_diag, lower_diag, queens_placed);

                board[row_i][col] = '.';

                queens_placed[row_i] = 0;

                upper_diag[n - 1 + col - row_i] = 0;

                lower_diag[row_i + col] = 0;
            }
        }
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

    int n;

    cin >> n;

    vector<string> board(n, string(n, '.'));

    vector<bool> upper_diag(2 * n - 1, 0),
        lower_diag(2 * n - 1, 0),
        queens_placed(n, 0);

    s.n_queens(0, n, board);

    // s.n_queens_optimal(0, n, board, upper_diag, lower_diag, queens_placed);

    // print_2d_vector<string>(s.result);

    return 0;
}