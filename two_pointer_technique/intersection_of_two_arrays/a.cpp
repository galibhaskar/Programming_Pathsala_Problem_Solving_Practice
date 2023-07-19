#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
    {
        vector<int> result;

        sort(nums1.begin(), nums1.end());

        sort(nums2.begin(), nums2.end());

        int i = 0, j = 0;

        while (i < nums1.size() && j < nums2.size())
        {
            if (nums1[i] == nums2[j])
            {
                result.push_back(nums1[i]);

                i++;
                j++;

                while (i < nums1.size() && nums1[i] == nums1[i - 1])
                    i++;

                while (j < nums2.size() && nums2[j] == nums2[j - 1])
                    j++;
            }

            else if (nums1[i] > nums2[j])
                j++;

            else
                i++;
        }

        return result;
    }
};

template <typename T>
void print_vector(vector<T> arr)
{
    cout << "-------vector begin-----" << endl;

    for (auto ele : arr)
        cout << ele << " ";

    cout << "-------vector end-----" << endl;
}

int main(int argc, char const *argv[])
{
    Solution s;

    vector<int> a{4, 9, 5}, b{9, 4, 9, 8, 4};

    print_vector<int>(s.intersection(a, b));

    return 0;
}