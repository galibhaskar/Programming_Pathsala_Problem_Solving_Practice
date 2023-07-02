#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    static bool cmp(pair<int, int> &a, pair<int, int> &b)
    {
        return a.first > b.first;
    }

    int find_max_jobs(vector<int> &deadlines, vector<int> &profits, int max_days)
    {
        vector<pair<int, int>> jobs;

        for (int i = 0; i < deadlines.size(); i++)
            jobs.push_back({profits[i], deadlines[i]});

        sort(jobs.begin(), jobs.end(), cmp);

        map<int, int> days;

        // insertion into map
        for (int i = 0; i <= max_days; i++)
            days[i + 1] = 0;

        int total_profit = 0;

        for (auto job : jobs)
        {
            cout << "p:" << job.first << " d:" << job.second << endl;

            auto it = days.upper_bound(job.second);

            if (it != days.begin())
            {
                it--;

                days.erase(it->first);

                total_profit += job.first;
            }
        }

        return total_profit;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;

    vector<int> deadlines{3, 5, 2, 2, 7, 3},
        profit{90, 75, 50, 60, 40, 20};

    int max_days = 7;

    cout << s.find_max_jobs(deadlines, profit, max_days);

    return 0;
}