#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int count = 0;
    // l - count of open paranthesis
    // r - count of closed paranthesis
    // subset - string with balanced paranthesis
    // n - no of pairs of the paranthesis
    void count_balanced_parathensis_subsets(int l, int r, char *subset, int subset_length, int n)
    {
        // case - 1: l == r
        // a) string complete:
        // do nothing
        // b) string is incomplete
        // next possibility is open paranthesis
        if (l == r)
        {
            if (subset_length == 2 * n)
            {
                subset[subset_length] = '\0';
                cout << "possibility:" << subset << endl;
                count++;

                return;
            }

            else
            {
                subset[subset_length] = '(';

                return count_balanced_parathensis_subsets(l + 1, r, subset, subset_length + 1, n);
            }
        }

        // case - 2: l>r
        // a) l == n
        // next possibility is closed
        // b) l != n
        // next possibility are open/close
        if (l > r)
        {
            if (l == n)
            {
                subset[subset_length] = ')';

                return count_balanced_parathensis_subsets(l, r + 1, subset, subset_length + 1, n);
            }

            else
            {

                subset[subset_length] = '(';

                count_balanced_parathensis_subsets(l + 1, r, subset, subset_length + 1, n);

                subset[subset_length] = ')';

                count_balanced_parathensis_subsets(l, r + 1, subset, subset_length + 1, n);
            }
        }
    }
};

int main(int argc, char const *argv[])
{

    Solution s;

    int n;

    cin >> n;

    if (n != 0)
    {
        char *subset = new char[2 * n];

        s.count_balanced_parathensis_subsets(0, 0, subset, 0, n);
    }

    cout << "count:" << s.count << endl;

    return 0;
}