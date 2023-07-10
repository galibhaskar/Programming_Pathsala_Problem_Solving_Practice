#include <bits/stdc++.h>

using namespace std;

bool cmp(pair<char, int> a, pair<char, int> b)
{
    return a.second < b.second;
}

class Solution
{
public:
    string customSortString(string order, string s)
    {
        vector<int> rank(26, INT_MAX);

        for (int i = 0; i < order.size(); i++)
            rank[order[i] - 'a'] = i;

        vector<pair<char, int>> vec;

        for (char ch : s)
            vec.push_back({ch, rank[ch - 'a']});

        sort(vec.begin(), vec.end(), cmp);

        string result = "";

        for (auto i : vec)
            result += i.first;

        return result;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;

    string order, t;

    cin >> order >> t;

    cout << s.customSortString(order, t);

    return 0;
}