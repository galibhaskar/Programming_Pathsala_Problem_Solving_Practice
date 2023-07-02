#include <bits/stdc++.h>

using namespace std;

template <typename T>
void print_vector(vector<T> arr)
{
    cout << "-------vector begin-----" << endl;

    for (auto ele : arr)
        cout << ele << " ";

    cout << "-------vector end-----" << endl;
}

class Solution
{
public:
    void calculate_suffix_sum(vector<int> &arr)
    {
        for (int i = arr.size() - 2; i >= 0; i--)
            arr[i] += arr[i + 1];
    }

    vector<int> process_range_queries(vector<pair<int, int>> &queries, int n)
    {
        vector<int> arr(n, 0);

        for (int i = 0; i < queries.size(); i++)
        {
            arr[queries[i].second]++;

            if (queries[i].first != 0)
                arr[queries[i].first - 1]--;

            // print_vector<int>(arr);
        }

        calculate_suffix_sum(arr);

        return arr;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;

    vector<pair<int, int>> queries{
        {2, 4},
        {3, 6},
        {1, 2},
        {3, 5}};

    print_vector<int>(s.process_range_queries(queries, 8));

    return 0;
}