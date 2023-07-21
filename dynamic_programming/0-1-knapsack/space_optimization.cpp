#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int knapSack(int W, int wt[], int val[], int n)
    {
        vector<int> arr(W + 1, 0), temp(W + 1, 0);

        for (int i = 1; i < n + 1; i++)
        {
            for (int j = 1; j < W + 1; j++)
            {
                temp[j] = arr[j];

                if (j - wt[i - 1] >= 0)
                    temp[j] = max(temp[j],
                                  val[i - 1] + arr[j - wt[i - 1]]);
            }

            arr = temp;
        }

        return arr[W];
    }
};

int main(int argc, char const *argv[])
{
    Solution s;

    int wt[3] = {4, 5, 1};

    int val[3] = {1, 2, 3};

    int N = 3, W = 4;

    cout << s.knapSack(W, wt, val, N);

    return 0;
}