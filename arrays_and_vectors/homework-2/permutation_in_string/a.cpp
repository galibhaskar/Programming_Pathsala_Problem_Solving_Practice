#include <bits/stdc++.h>

using namespace std;

class Solution
{
private:
    bool check_frequencies_match(map<char, int> s1_freq, map<char, int> s2_freq)
    {
        for (auto i : s1_freq)
        {
            if (s2_freq[i.first] != i.second)
                return false;
        }

        return true;
    }

public:
    string is_permutation(string s1, string s2)
    {
        int window_size = s1.size();

        if (window_size > s2.size())
            return "False";

        map<char, int> s1_freq, s2_freq;

        for (auto i : s1)
            s1_freq[i]++;

        for (auto i : s2.substr(0, window_size))
            s2_freq[i]++;

        if (check_frequencies_match(s1_freq, s2_freq))
            return "True";

        int i = window_size;
        while (i < s2.size())
        {
            s2_freq[s2[i - window_size]]--;

            s2_freq[s2[i]]++;

            if (check_frequencies_match(s1_freq, s2_freq))
                return "True";

            i++;
        }

        return "False";
    }
};

int main(int argc, char const *argv[])
{
    string s1, s2;

    Solution s;

    int test_cases;

    cin >> test_cases;

    while (test_cases--)
    {
        cin >> s1 >> s2;

        cout << s.is_permutation(s1, s2) << endl;
    }

    return 0;
}