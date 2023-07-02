#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool find_word(vector<vector<char>> &board,
                   string word, int index,
                   int row, int col,
                   vector<vector<bool>> &visited)
    {
        if (index == word.length())
            return true;

        visited[row][col] = 1;

        // top
        if (row - 1 >= 0 && visited[row - 1][col] != 1 && board[row - 1][col] == word[index])
        {
            if (find_word(board, word, index + 1, row - 1, col, visited) == true)
                return true;
        }

        // right
        if (col + 1 < board[0].size() && visited[row][col + 1] != 1 && board[row][col + 1] == word[index])
        {
            if (find_word(board, word, index + 1, row, col + 1, visited) == true)
                return true;
        }

        // bottom
        if (row + 1 < board.size() && visited[row + 1][col] != 1 && board[row + 1][col] == word[index])
        {
            if (find_word(board, word, index + 1, row + 1, col, visited) == true)
                return true;
        }

        // left
        if (col - 1 >= 0 && visited[row][col - 1] != 1 && board[row][col - 1] == word[index])
        {
            if (find_word(board, word, index + 1, row, col - 1, visited) == true)
                return true;
        }

        visited[row][col] = 0;

        return false;
    }

    bool exist(vector<vector<char>> &board, string word)
    {
        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size()));

        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                if (word[0] == board[i][j])
                {
                    if (find_word(board, word, 1, i, j, visited) == true)
                    {
                        return true;
                    }
                }
            }
        }

        return false;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;

    vector<vector<char>> board = {
        {'A', 'B', 'C', 'E'},
        {'S', 'F', 'C', 'S'},
        {'A', 'D', 'E', 'E'}};

    string word = "ABCCED";

    cout << (s.exist(board, word) ? "true" : "false");

    return 0;
}