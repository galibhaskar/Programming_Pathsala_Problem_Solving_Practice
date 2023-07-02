#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<string> combinations;

    void get_letter_combinations(vector<string> &dictionary, int index, string &digits, char *letter_combination, int lc_index)
    {
        if (index == digits.length())
        {
            letter_combination[lc_index] = '\0';

            combinations.push_back(letter_combination);

            return;
        }

        string button_chars = dictionary[digits[index] - '2'];

        for (char ch : button_chars)
        {
            letter_combination[lc_index] = ch;

            get_letter_combinations(dictionary, index + 1, digits, letter_combination, lc_index + 1);
        }
    }
};

int main(int argc, char const *argv[])
{
    Solution s;

    vector<string> dictionary{
        "abc",
        "def",
        "ghi",
        "jkl",
        "mno",
        "prqs",
        "tuv",
        "wxyz"};

    string digits;

    cin >> digits;

    char *letter_combination = new char[digits.length()];

    s.get_letter_combinations(dictionary, 0, digits, letter_combination, 0);

    for (auto i : s.combinations)
        cout << i << endl;

    return 0;
}