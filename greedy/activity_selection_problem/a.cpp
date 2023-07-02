#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    static bool cmp(pair<int, int> &a, pair<int, int> &b)
    {
        return a.second < b.second;
    }

    void find_max_no_of_activities(vector<pair<int, int>> &activity_list)
    {
        sort(activity_list.begin(), activity_list.end(), cmp);

        int end_time = activity_list[0].second, activity_count = 1;

        for (int i = 1; i < activity_list.size(); i++)
        {
            if (activity_list[i].first <= end_time)
            {
                activity_count++;

                end_time = activity_list[i].second;
            }
        }

        cout << "max activities that can be done:" << activity_count << endl;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;

    vector<pair<int, int>> activity_list{
        {1, 2},
        {3, 4},
        {0, 6},
        {5, 7},
        {8, 9},
        {5, 9}};

    s.find_max_no_of_activities(activity_list);

    return 0;
}