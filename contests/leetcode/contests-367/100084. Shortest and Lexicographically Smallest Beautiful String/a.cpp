#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    string shortestBeautifulSubstring(string s, int k)
    {
        // cout << "string:" << s;
        // cout << "first index string:" << (s[0] == 1);
        int start = 0, end = 0, count = (s[start] == '1');

        // cout << "count:" << count << endl;

        int minLength = INT_MAX, length = 0;

        string validSubstring = "";

        while (end != s.length())
        {
            if (count < k)
                count += (s[++end] == '1');

            else if (count > k)
                count -= (s[start++] == '1');

            else
            {
                length = end - start + 1;

                cout << "length:" << length << " min length:" << minLength << endl;
                cout << "valid substring:" << validSubstring << endl;

                if (minLength >= length)
                {
                    if (validSubstring == "" ||
                        validSubstring.length() > length ||
                        (validSubstring.length() == length &&
                         validSubstring.compare(s.substr(start, length)) > 0))
                        validSubstring = s.substr(start, length);

                    minLength = length;

                    cout << "length:" << length << " substring:" << validSubstring << endl;
                }
                count -= (s[start++] == '1');
                length = 0;
            }
        }

        cout << "valid string:" << validSubstring << " length:" << validSubstring.length() << endl;

        cout << "minlength:" << minLength << endl;

        return validSubstring;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    int k = 10;
    cout << s.shortestBeautifulSubstring("001110101101101111", k);
    return 0;
}