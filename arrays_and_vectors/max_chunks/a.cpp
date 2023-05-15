/*
Given an permutation of array elements ranging from 0 to n-1(no-repetitions).
Find the max no of chunks that can be divided so that each chunk is sorted individually and combined,
forms a complete sorted array.

Example:
6
1 2 0 4 3 5

1 2 0   -> First chunk  -> 0 1 2
4 3     -> second chunk -> 3 4
5       -> last chunk   -> 5

combined array of all chunks -> 0 1 2 3 4 5

*/

#include <bits/stdc++.h>

using namespace std;

template <typename T>
vector<T> scan_vector()
{
    vector<T> arr;

    int n;

    cin >> n;

    T input;

    while (n--)
    {
        cin >> input;
        arr.push_back(input);
    }

    return arr;
}

template <typename T>
void print_vector(vector<T> arr)
{
    cout << "-------vector begin-----" << endl;

    for (auto ele : arr)
        cout << ele << " ";

    cout << "-------vector end-----" << endl;
}

bool can_be_chunks(vector<int> &v, int i, int j)
{
    int count = 0;

    // cout << "can be chunks-> i: " << i << " j:" << j << endl;

    for (int index = i; index <= j; index++)
        if (v[index] >= i && v[index] <= j)
            count++;

    if (count == (j - i + 1))
        return true;

    return false;
}

// Complexity : O(N^2)
int get_max_chunks(vector<int> v)
{
    int n = v.size();

    int chunks_count = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            // cout << " i: " << i << " j:" << j << endl;
            if (can_be_chunks(v, i, j))
            {
                chunks_count++;
                i = j;
                break;
            }
        }
    }
    return chunks_count;
}

// complexity : O(N)
int get_max_chunks_pref_max(vector<int> v)
{
    vector<int> pref_max(v.size(), 0);

    int chunks_count = 0;

    pref_max[0] = v[0];

    for (int i = 1; i < v.size(); i++)
        pref_max[i] = max(pref_max[i - 1], v[i]);

    // print_vector<int>(pref_max);

    for (int i = 0; i < pref_max.size(); i++)
    {
        if (pref_max[i] == i)
            chunks_count++;
    }

    return chunks_count;
}

int main(int argc, char const *argv[])
{
    vector<int> v = scan_vector<int>();

    cout << "max chunks:" << get_max_chunks(v) << endl;

    cout << "max chunks using pref max:" << get_max_chunks_pref_max(v) << endl;

    return 0;
}
