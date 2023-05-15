#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int size;
    vector<vector<int>> pascal;

    Solution(int value)
    {
        size = value;
        pascal = vector<vector<int>>(value, vector<int>(value, 0));
    }

    void construct_pascal_triangle(int size)
    {
        pascal[0][0] = 1;

        for (int i = 1; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                if (j == 0 || j == i)
                    pascal[i][j] = 1;

                else
                    pascal[i][j] = pascal[i - 1][j - 1] + pascal[i - 1][j];
            }
        }
    }

    void print_pascal_triangle(int size)
    {
        construct_pascal_triangle(size);

        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j <= i; j++)
                cout << pascal[i][j] << " ";
            cout << endl;
        }
    }

    // void compute_n_c_r(int n, int r)
    // {
    //     construct_pascal_triangle(n + 1);

    //     print_pascal_triangle(n + 1);

    //     cout << pascal[n][r] << endl;
    // }
};

int main(int argc, char const *argv[])
{
    int n;

    cin >> n;

    Solution *s = new Solution(n + 1);

    // s->compute_n_c_r(n, r);

    s->print_pascal_triangle(n);

    return 0;
}