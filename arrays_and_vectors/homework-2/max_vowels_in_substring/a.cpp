#include <bits/stdc++.h>

using namespace std;

class Solution
{
private:
    bool is_vowel(char c)
    {
        c = tolower(c);

        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
            return true;

        return false;
    }

public:
    int get_max_vowels_in_substring(string s, int k)
    {

        int i = 0, vowels_count = 0, max_vowel_count = INT_MIN;

        while (i < k)
        {
            if (is_vowel(s[i++]))
                vowels_count++;
        }

        max_vowel_count = max(max_vowel_count, vowels_count);

        while (i < s.size())
        {
            if (is_vowel(s[i - k]))
                vowels_count--;

            if (is_vowel(s[i]))
                vowels_count++;

            max_vowel_count = max(max_vowel_count, vowels_count);

            i++;
        }

        return max_vowel_count;
    }
};

int main(int argc, char const *argv[])
{
    int test_cases;

    cin >> test_cases;

    while (test_cases--)
    {
        string s;

        int k;

        cin >> s >> k;

        Solution sol;

        cout << sol.get_max_vowels_in_substring(s, k) << endl;
    }

    return 0;
}