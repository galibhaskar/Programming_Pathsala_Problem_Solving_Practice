#include <bits/stdc++.h>

using namespace std;

template <typename T>
vector<T> scan_vector(int size = 0)
{
    vector<T> arr;

    int n;

    if (size == 0)
        cin >> n;

    else
        n = size;

    T input;

    while (n--)
    {
        cin >> input;
        arr.push_back(input);
    }

    return arr;
}

long int get_max_possible_score(vector<int> &v, int size, vector<pair<int, int>> &queries, int queries_count)
{
    vector<long int> psum(size + 1, 0);

    psum[0] = 0;

    for (int i = 1; i <= size; i++)
        psum[i] = psum[i - 1] + v[i - 1];

    pair<int, int> elements;

    long int total, possible_score = 0, neg_max_value = INT_MIN;

    for (int i = 0; i < queries_count; i++)
    {
        elements = queries[i];

        total = psum[elements.second] - psum[elements.first - 1];

        // cout << elements.first << " " << elements.second << " total:" << total << endl;

        if (total > 0)
            possible_score += total;

        else if (total <= 0 && neg_max_value < total)
            neg_max_value = total;
    }

    if (possible_score >= 0)
        return possible_score;

    return neg_max_value;
}

int main(int argc, char const *argv[])
{
    int n, m, l, r;

    cin >> n >> m;

    vector<int> v = scan_vector<int>(n);

    vector<pair<int, int>> queries;

    while (m--)
    {
        cin >> l >> r;
        queries.push_back({l, r});
    }

    cout << get_max_possible_score(v, v.size(), queries, queries.size());

    return 0;
}