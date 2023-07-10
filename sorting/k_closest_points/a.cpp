#include <bits/stdc++.h>

using namespace std;

bool cmp(vector<int> a, vector<int> b)
{
    return ((a[0] * a[0]) + (a[1] * a[1])) < ((b[0] * b[0]) + (b[1] * b[1]));
}

bool cmp1(pair<vector<int>, int> a, pair<vector<int>, int> b)
{
    return a.second < b.second;
}

class Solution
{
public:
    vector<vector<int>> kClosest(vector<vector<int>> &points, int k)
    {
        sort(points.begin(), points.end(), cmp);

        vector<vector<int>> result;

        for (int i = 0; i < k; i++)
            result.push_back(points[i]);

        return result;
    }

    vector<vector<int>> kClosest2(vector<vector<int>> &points, int k)
    {
        vector<pair<vector<int>, int>> vec;

        for (int i = 0; i < points.size(); i++)
        {
            vec.push_back({points[i],
                           (points[i][0] * points[i][0]) +
                               (points[i][1] * points[i][1])});
        }

        sort(vec.begin(), vec.end(), cmp1);

        vector<vector<int>> result;

        for (int i = 0; i < k; i++)
            result.push_back(vec[i].first);

        return result;
    }
};

template <typename T>
void print_2d_vector(vector<vector<T>> arr)
{
    cout << "-------vector begin-----" << endl;

    for (auto ele : arr)
    {
        for (auto i : ele)
            cout << i << " ";
        cout << endl;
    }

    cout << "-------vector end-----" << endl;
}

int main(int argc, char const *argv[])
{
    Solution s;
    int k;

    vector<vector<int>> arr{
        {3, 3}, {5, -1}, {-2, 4}};

    cin >> k;

    print_2d_vector<int>(s.kClosest2(arr, k));

    return 0;
}