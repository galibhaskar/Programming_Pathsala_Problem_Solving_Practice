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
    void count_balanced_parathensis_subsets(int l, int r, string subset, int n)
    {
        // case - 1: l == r
        // a) string complete:
        // do nothing
        // b) string is incomplete
        // next possibility is open paranthesis
        if (l == r)
        {
            if (subset.length() == 2 * n)
            {
                cout << "possibility:" << subset << endl;
                count++;
                return;
            }

            else
                return count_balanced_parathensis_subsets(l + 1, r, subset + '(', n);
        }

        // case - 2: l>r
        // a) l == n
        // next possibility is closed
        // b) l != n
        // next possibility are open/close
        if (l > r)
        {
            if (l == n)
                return count_balanced_parathensis_subsets(l, r + 1, subset + ')', n);

            else
            {
                count_balanced_parathensis_subsets(l + 1, r, subset + '(', n);

                count_balanced_parathensis_subsets(l, r + 1, subset + ')', n);
            }
        }
    }
};

int main(int argc, char const *argv[])
{

    Solution s;

    int n;

    cin >> n;

    s.count_balanced_parathensis_subsets(0, 0, "", n);

    cout << "count:" << s.count << endl;

    return 0;
}