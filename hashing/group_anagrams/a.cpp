#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> names)
    {
        unordered_map<string, vector<string>> m;

        string sortedName;

        for (auto name : names)
        {
            sortedName = name;

            sort(sortedName.begin(), sortedName.end());

            m[sortedName].push_back(name);
        }

        vector<vector<string>> result;

        for (auto item : m)
            result.push_back(item.second);

        return result;
    }
};

template <typename T>
void print_vector(vector<T> arr)
{
    cout << "-------vector begin-----" << endl;

    for (auto ele : arr)
        cout << ele << " ";

    cout << "-------vector end-----" << endl;
}

void print_anagrams(vector<vector<string>> groupedAnagrams)
{
    for (auto i : groupedAnagrams)
    {
        print_vector<string>(i);

        cout << endl;
    }
}

int main(int argc, char const *argv[])
{
    Solution s;

    print_anagrams(s.groupAnagrams({"bca", "aatc", "caa", "cab", "cata", "bac"}));

    return 0;
}