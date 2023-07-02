#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int count = 0;

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

    void find_paths(vector<vector<int>> &maze, int row, int col, int visited_count, int &zero_count)
    {
        if (maze[row][col] == 2)
        {

            if (visited_count == zero_count)
            {
                print_2d_vector<int>(maze);

                // cout << "count incremented as visited:"
                //      << visited_count << " required" << zero_count << endl;

                count++;
            }
            return;
        }

        maze[row][col] = -2;
        visited_count++;

        // cout << "row:" << row << " col:" << col << endl;

        // top
        if (row - 1 >= 0 && maze[row - 1][col] >= 0)
        {
            // cout << "top move -row:" << row - 1 << " col" << col << endl;
            find_paths(maze, row - 1, col, visited_count, zero_count);
        }

        // right
        // cout << "right move check-row" << row
        //      << " col:" << col + 1 << " state:"
        //      << maze[row][col + 1] << endl;

        // cout << "maze size:" << maze.size() << endl;

        if (col + 1 < maze[0].size() && maze[row][col + 1] >= 0)
        {
            // cout << "right move -row:" << row << " col" << col + 1 << endl;
            find_paths(maze, row, col + 1, visited_count, zero_count);
        }

        // down
        if (row + 1 < maze.size() && maze[row + 1][col] >= 0)
        {
            // cout << "down move -row:" << row + 1 << " col" << col << endl;
            find_paths(maze, row + 1, col, visited_count, zero_count);
        }

        // left
        if (col - 1 >= 0 && maze[row][col - 1] >= 0)
        {
            // cout << "left move -row:" << row << " col" << col - 1 << endl;
            find_paths(maze, row, col - 1, visited_count, zero_count);
        }

        maze[row][col] = 0;
        visited_count--;
    }

    void count_paths_to_destination(vector<vector<int>> &maze)
    {
        int zero_count = 0;
        pair<int, int> start_point;

        for (int i = 0; i < maze.size(); i++)
            for (int j = 0; j < maze[0].size(); j++)
            {
                if (maze[i][j] == 1)
                {
                    start_point.first = i;
                    start_point.second = j;
                }

                if (maze[i][j] == 0)
                    zero_count++;
            }

        int visited_count = -1;

        find_paths(maze, start_point.first, start_point.second, visited_count, zero_count);
    }
};

int main(int argc, char const *argv[])
{
    Solution s;

    // vector<vector<int>> maze{
    //     {0, 1, 0},
    //     {0, 0, 0},
    //     {0, 2, -1}};

    vector<vector<int>> maze{
        {1, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 2}};

    s.count_paths_to_destination(maze);

    cout << "path count:" << s.count << endl;

    return 0;
}