#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    static bool cmp(pair<int, int> a, pair<int, int> b)
    {
        return a.second < b.second;
    }

    int find_max_activity_selection_for_two_persons(vector<pair<int, int>> &activity_list)
    {
        sort(activity_list.begin(), activity_list.end(), cmp);

        int end_time_1 = 0, end_time_2 = 0, p1_count = 0, p2_count = 0;

        for (int i = 0; i < activity_list.size(); i++)
        {
            // cout<<" activity start:"
            //     <<activity_list[i].first
            //     <<" end:"<<activity_list[i].second<<endl;


            if (end_time_1 <= activity_list[i].first &&
                end_time_2 <= activity_list[i].first)
            {
                if (max(end_time_1, end_time_2) == end_time_1)
                {
                    end_time_1 = activity_list[i].second;
                    p1_count++;
                }

                else
                {
                    end_time_2 = activity_list[i].second;
                    p2_count++;
                }
            }

            else if (end_time_1 <= activity_list[i].first)
            {
                end_time_1 = activity_list[i].second;

                p1_count++;
            }

            else if (end_time_2 <= activity_list[i].first)
            {
                end_time_2 = activity_list[i].second;

                p2_count++;
            }

            // cout << " end time 1:" << end_time_1
            //      << " p1 count:" << p1_count
            //      << " end time 2:" << end_time_2
            //      << " p2 count:" << p2_count << endl;
        }

        return p1_count + p2_count;
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

    cout << "max activities"
         << s.find_max_activity_selection_for_two_persons(activity_list);

    return 0;
}