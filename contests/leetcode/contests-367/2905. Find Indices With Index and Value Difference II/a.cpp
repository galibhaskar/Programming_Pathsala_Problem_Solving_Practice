#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    template <typename T>
    void print_vector(vector<T> arr)
    {
        cout << "-------vector begin-----" << endl;

        for (auto ele : arr)
            cout << ele << " ";

        cout << "-------vector end-----" << endl;
    }

    vector<int> findIndices(vector<int> &nums, int indexDifference, int valueDifference)
    {
        if (nums.size() > indexDifference)
        {
            vector<int> suffixMaxIndex(nums.size()), suffixMinIndex(nums.size());

            suffixMaxIndex[nums.size() - 1] = nums.size() - 1;

            suffixMinIndex[nums.size() - 1] = nums.size() - 1;

            for (int index = nums.size() - 2; index >= 0; index--)
            {
                if (nums[suffixMaxIndex[index + 1]] > nums[index])
                    suffixMaxIndex[index] = suffixMaxIndex[index + 1];
                else
                    suffixMaxIndex[index] = index;

                if (nums[suffixMinIndex[index + 1]] < nums[index])
                    suffixMinIndex[index] = suffixMinIndex[index + 1];
                else
                    suffixMinIndex[index] = index;
            }

            // print_vector<int>(suffixMaxIndex);
            // print_vector<int>(suffixMinIndex);

            for (int index = 0; index < nums.size() - indexDifference; index++)
            {
                if (abs(nums[index] - nums[suffixMaxIndex[index + indexDifference]]) >= valueDifference)
                    return vector<int>{index, suffixMaxIndex[index + indexDifference]};

                else if (abs(nums[index] - nums[suffixMinIndex[index + indexDifference]]) >= valueDifference)
                    return vector<int>{index, suffixMinIndex[index + indexDifference]};
            }
        }

        return vector<int>{-1, -1};
    }
};

int main(int argc, char const *argv[])
{
    Solution s;

    vector<int> arr = {0};

    s.print_vector<int>(s.findIndices(arr, 100000, 1000000000));

    return 0;
}