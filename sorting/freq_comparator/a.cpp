#include <bits/stdc++.h>

using namespace std;

struct Item
{
    int element;
    int frequency;
    int index;

    Item(int ele, int freq, int ind)
    {
        element = ele;
        frequency = freq;
        index = ind;
    }
};

bool cmp(Item a, Item b)
{
    if (a.frequency != b.frequency)
        return a.frequency > b.frequency;

    if (a.element != b.element)
        return a.element < b.element;

    return a.index < b.index;
}

class Solution
{
public:
    // static bool cmp(Item a, Item b)
    // {
    //     if (a.frequency != b.frequency)
    //         return a.frequency < b.frequency;

    //     if (a.element != b.element)
    //         return a.element < b.element;

    //     return a.index < b.index;
    // }

    void sort_based_on_rules(vector<int> &arr)
    {
        vector<Item> vec;

        map<int, int> freq;

        for (auto i : arr)
            freq[i]++;

        for (int i = 0; i < arr.size(); i++)
            vec.push_back(Item(arr[i], freq[arr[i]], i));

        sort(vec.begin(), vec.end(), cmp);

        for (int i = 0; i < vec.size(); i++)
            arr[i] = vec[i].element;
    }
};

template <typename T>
void print_vector(vector<T> arr)
{
    for (auto ele : arr)
        cout << ele << " ";
}

int main(int argc, char const *argv[])
{
    Solution s;

    int test_cases, n, num;

    cin >> test_cases;

    while (test_cases--)
    {
        cin >> n;

        vector<int> arr;

        for (int i = 0; i < n; i++)
        {
            cin >> num;

            arr.push_back(num);
        }

        s.sort_based_on_rules(arr);

        print_vector<int>(arr);
    }
    return 0;
}