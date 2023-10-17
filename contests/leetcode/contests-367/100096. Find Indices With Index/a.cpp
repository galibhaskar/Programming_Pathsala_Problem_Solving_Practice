#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<int> findIndices(vector<int> &nums, int indexDifference, int valueDifference)
    {
        for (int index = 0; index < nums.size() - indexDifference; index++)
        {
            for (int secondIndex = 0; secondIndex < nums.size(); secondIndex++)
                if (
                    abs(index - secondIndex) >= indexDifference &&
                    abs(nums[index] - nums[index + indexDifference]) >= valueDifference)
                {
                    return vector<int>{index, secondIndex};
                }
        }

        return vector<int>{-1, -1};
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    // s.function();
    return 0;
}