#include <bits/stdc++.h>

using namespace std;

#define mod 12345

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

class Solution
{
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>> &grid)
    {
        vector<vector<int>> suffixProd(grid.size(), vector<int>(grid[0].size()));

        long long int prevProd = 1, currProd = 1;

        for (int rowIndex = grid.size() - 1; rowIndex >= 0; rowIndex--)
        {
            for (int colIndex = grid[rowIndex].size() - 1; colIndex >= 0; colIndex--)
            {
                // cout << "element:" << grid[rowIndex][colIndex] << " ";

                suffixProd[rowIndex][colIndex] = ((currProd % mod) * (grid[rowIndex][colIndex] % mod)) % mod;

                currProd = suffixProd[rowIndex][colIndex];
            }
            // cout << endl;
        }

        // print_2d_vector<int>(suffixProd);

        // print_2d_vector<int>(suffixProd);

        currProd = 1;

        prevProd = 1;

        for (int rowIndex = 0; rowIndex < grid.size(); rowIndex++)
        {
            for (int colIndex = 0; colIndex < grid[rowIndex].size(); colIndex++)
            {
                currProd = grid[rowIndex][colIndex];

                // cout << "currProd:" << currProd << endl;
                // cout << "prevProd:" << prevProd << endl;

                if (colIndex + 1 < grid[rowIndex].size())
                {
                    // cout << "suffix prod:" << suffixProd[rowIndex][colIndex + 1] << endl;
                    grid[rowIndex][colIndex] = ((prevProd % mod) * (suffixProd[rowIndex][colIndex + 1] % mod)) % mod;
                }
                else if (rowIndex + 1 < grid.size())
                {
                    // cout << "suffix prod-else if:" << suffixProd[rowIndex + 1][(colIndex + 1) % grid[rowIndex].size()] << endl;
                    grid[rowIndex][colIndex] = ((prevProd % mod) * (suffixProd[rowIndex + 1][(colIndex + 1) % grid[rowIndex].size()] % mod)) % mod;
                }
                else
                {
                    // cout << "suffix prod-else:1" << endl;
                    grid[rowIndex][colIndex] = prevProd % mod;
                }

                prevProd = ((prevProd % mod) * (currProd % mod)) % mod;

                // print_2d_vector<int>(grid);
            }

            // cout << endl;
        }

        return grid;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;

    vector<vector<int>> grid{{12345}, {2}, {1}};

    print_2d_vector<int>(s.constructProductMatrix(grid));

    return 0;
}