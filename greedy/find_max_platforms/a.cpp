#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    // range quries based approach
    int suffix_sum_max(vector<int> &arr)
    {
        int max_ele = arr[arr.size() - 1];

        for (int i = arr.size() - 2; i >= 0; i--)
        {
            arr[i] += arr[i + 1];
            max_ele = max(max_ele, arr[i]);
        }

        return max_ele;
    }

    int find_max_platforms(vector<int> &arrivals, vector<int> &departures)
    {
        int max_departure_time = *max_element(departures.begin(), departures.end());

        cout << "max depart time:" << max_departure_time << endl;

        vector<int> platform_timings(max_departure_time + 1, 0);

        for (int i = 0; i < arrivals.size(); i++)
        {
            platform_timings[departures[i]]++;

            if (arrivals[i] > 0)
                platform_timings[arrivals[i] - 1]--;
        }

        return suffix_sum_max(platform_timings);
    }
};

int main(int argc, char const *argv[])
{
    Solution s;

    vector<int> arrivals{1, 3, 6, 7},
        departures{5, 9, 8, 10};

    cout << "max no of platforms:"
         << s.find_max_platforms(arrivals, departures);

    return 0;
}