#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    void get_valid_brackets(int op, int cp, int n, int ob, int cb, int m, char *subset, int subset_length)
    {
        cout << "op:" << op << " cp:" << cp << endl
             << "ob:" << ob << " cb:" << cb << endl
             << "last element" << subset[subset_length - 1] << endl
             << "subset" << subset << " length:" << subset_length << endl;

        if (op == cp && ob == cb)
        {
            if (subset_length == 2 * (n + m))
            {
                cout << endl
                     << endl
                     << "case 1.1"
                     << endl
                     << endl;
                subset[subset_length] = '\0';

                cout << subset << endl;

                return;
            }
        }

        else
        {
            if (op != n)
            {
                cout << endl
                     << endl
                     << "case 1.2.1"
                     << endl
                     << endl;
                subset[subset_length] = '(';

                get_valid_brackets(op + 1, cp, n, ob, cb, m, subset, subset_length + 1);
            }

            if (ob != m)
            {
                cout << endl
                     << endl
                     << "case 1.2.2"
                     << endl
                     << endl;
                subset[subset_length] = '{';

                get_valid_brackets(op, cp, n, ob + 1, cb, m, subset, subset_length + 1);
            }
        }
    }

    if (op > cp || ob > cp)
    {
        cout << "second condition" << endl;

        if (subset[subset_length - 1] == '(')
        {
            if (op == n)
            {
                cout << endl
                     << endl
                     << "case 2.1.1"
                     << endl
                     << endl;

                subset[subset_length] = ')';

                return get_valid_brackets(op, cp + 1, n, ob, cb, m, subset, subset_length + 1);
            }

            else
            {

                cout << endl
                     << endl
                     << "case 2.1.2"
                     << endl
                     << endl;
                subset[subset_length] = '{';

                return get_valid_brackets(op, cp, n, ob + 1, cb, m, subset, subset_length + 1);
            }
        }

        else if (subset[subset_length - 1] == '{')
        {
            if (ob == m)
            {
                cout << endl
                     << endl
                     << "case 2.2.1"
                     << endl
                     << endl;
                subset[subset_length] = '}';

                return get_valid_brackets(op, cp, n, ob, cb + 1, m, subset, subset_length + 1);
            }

            else
            {
                cout << endl
                     << endl
                     << "case 2.2.2"
                     << endl
                     << endl;

                subset[subset_length] = '(';

                return get_valid_brackets(op + 1, cp, n, ob, cb, m, subset, subset_length + 1);
            }
        }
    }
}
}
;

int main(int argc, char const *argv[])
{

    Solution s;

    int n, m;

    cin >> n >> m;

    char *subset = new char[2 * (n + m) + 1];

    s.get_valid_brackets(0, 0, n, 0, 0, m, subset, 0);

    return 0;
}