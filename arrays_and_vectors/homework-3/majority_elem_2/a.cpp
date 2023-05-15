#include <bits/stdc++.h>

using namespace std;

typedef long int lt;

class Solution
{
public:
    vector<lt> get_majority_element_moores_voting(vector<lt> &v, lt size)
    {
        lt first_major, second_major, first_votes = 0, second_votes = 0;

        for (auto elem : v)
        {
            if (first_votes == 0)
            {
                first_major = elem;
                first_votes++;
            }

            else if (second_votes == 0)
            {
                second_major = elem;
                second_votes++;
            }

            else if (first_major == elem)
                first_votes++;

            else if (second_major == elem)
                second_votes++;

            else
            {
                first_votes--;
                second_votes--;
            }
        }

        cout << "first:" << first_major << " votes:" << first_votes << endl;

        cout << "second:" << second_major << " votes:" << second_votes << endl;

        lt count1 = 0, count2 = 0;

        vector<lt> result;

        for (auto elem : v)
        {
            if (elem == first_major)
                count1++;

            if (elem == second_major)
                count2++;
        }

        if (count1 > (size / 3))
            result.push_back(first_major);

        if (count2 > (size / 3) && first_major != second_major)
            result.push_back(second_major);

        sort(result.begin(), result.end());

        return result;
    }

    vector<lt> get_majority_element(vector<lt> &v, lt size)
    {
        map<lt, lt> m;

        vector<lt> result;

        for (auto elem : v)
            m[elem]++;

        for (auto i : m)
        {
            if (i.second > (size / 3))
                result.push_back(i.first);
        }

        if (result.size() == 0)
            result.push_back(-1);

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

template <typename T, typename size_type>
vector<T> scan_vector(size_type size = 0)
{
    size_type n;

    if (size == 0)
        cin >> n;

    else
        n = size;

    vector<T> arr(n);

    for (auto i = 0; i < n; i++)
        cin >> arr[i];

    return arr;
}

int main(int argc, char const *argv[])
{

    lt test_cases;

    cin >> test_cases;

    Solution s;

    while (test_cases--)
    {
        vector<lt> v = scan_vector<lt, lt>();

        print_vector<lt>(s.get_majority_element_moores_voting(v, v.size()));
    }

    return 0;
}