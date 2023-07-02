#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    // fractional knapsnack: item can be broken if required
    static bool cmp(pair<int, int> &a, pair<int, int> &b)
    {
        // comparing based on the profit/weight ratio in descending order
        return a.first * b.second > a.second * b.first;
    }

    double find_max_profit(vector<int> &prices, vector<int> &weights, int bag_weight)
    {
        vector<pair<int, int>> items;

        for (int i = 0; i < prices.size(); i++)
            items.push_back({prices[i], weights[i]});

        sort(items.begin(), items.end(), cmp);

        double max_profit = 0;

        for (auto item : items)
        {

            // cout << " bag weight:" << bag_weight
            //      << " max profit:" << max_profit << endl;

            if (bag_weight >= item.second)
            {
                bag_weight -= item.second;

                max_profit += item.first;
            }

            else
            {
                if (bag_weight != 0)
                    max_profit += (((item.first * 1.0) / item.second) * bag_weight);

                break;
            }
        }

        return max_profit;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;

    vector<int> prices{4, 25, 12},
        weights{2, 5, 4};

    int W = 9;

    cout << s.find_max_profit(prices, weights, W);

    return 0;
}