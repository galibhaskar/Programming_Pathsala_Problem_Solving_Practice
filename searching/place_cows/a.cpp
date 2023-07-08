#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool is_possible(vector<int> &stalls, int cows, int distance)
    {
        // cout << "distance:" << distance << endl;

        int prev_position = stalls[0];

        cows--;

        for (int i = 1; i < stalls.size() && cows; i++)
        {
            if (prev_position + distance > stalls[i])
                continue;

            // cout << "cows:" << cows << " stall:" << stalls[i] << endl;

            cows--;

            prev_position = stalls[i];
        }

        if (cows == 0)
            return true;

        return false;
    }

    int place_cows(vector<int> &stalls, int cows)
    {
        if (cows > stalls.size())
            return 0;

        long long low = INT_MIN, high = INT_MAX, mid;

        while (low <= high)
        {
            mid = low + ((high - low) / 2);

            // cout << "mid:" << mid << endl;

            if (!is_possible(stalls, cows, mid))
                high = mid - 1;

            else
            {
                if (!is_possible(stalls, cows, mid + 1))
                    return mid;

                low = mid + 1;
            }
        }
    }
};

int main(int argc, char const *argv[])
{
    Solution s;

    int n, cows, test_cases, num;

    cin >> n;

    vector<int> stalls;

    for (int i = 0; i < n; i++)
    {
        cin >> num;

        stalls.push_back(num);
    }

    sort(stalls.begin(), stalls.end());

    cin >> test_cases;

    while (test_cases--)
    {
        cin >> cows;

        cout << s.place_cows(stalls, cows) << endl;
    }

    return 0;
}