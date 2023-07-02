#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int find_max_platforms(vector<pair<int, int>> &timings)
    {
        map<int, int> end_times;

        for (int i = 0; i < timings.size(); i++)
        {
            // cout << "printing the map" << endl;

            // for (auto i : end_times)
            //     cout << "first:" << i.first << " second:" << i.second << endl;

            // cout << "--------------------------------" << endl;

            auto iterator = end_times.upper_bound(timings[i].first);

            // cout << "timings:" << timings[i].first
            //      << " " << timings[i].second << endl;

            if (iterator == end_times.begin())
            {
                end_times[timings[i].second]++;
            }

            else
            {
                iterator--;

                iterator->second--;

                if (iterator->second == 0)
                    end_times.erase(iterator);

                end_times[timings[i].second]++;
            }
        }

        int count = 0;

        for (auto i : end_times)
            count += i.second;

        return count;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;

    vector<pair<int, int>> timings{
        {1, 4},
        {2, 4},
        {3, 9},
        {6, 8},
        {7, 10}};

    cout << "max platforms:"
         << s.find_max_platforms(timings);

    return 0;
}