#include <bits/stdc++.h>

using namespace std;

typedef long long int llt;

#define mod 1000000007

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

llt get_sum(vector<llt> &v, llt start, llt end)
{
    llt total = 0;

    while (start <= end)
        total += v[start++];

    return total;
}

// complexity : O(N^3)
llt get_sum_of_subarrays(vector<llt> &v, llt size)
{
    llt ans = 0;

    for (llt i = 0; i < size; i++)
    {
        for (llt j = i; j < size; j++)
        {
            ans += get_sum(v, i, j);
        }
    }

    return ans;
}

// complexity: O(N^2)
llt get_sum_of_subarrays_2(vector<llt> &v, llt size)
{
    llt ans = 0, total = 0;

    for (llt i = 0; i < size; i++)
    {
        total = 0;

        for (llt j = i; j < size; j++)
        {
            total += v[j];
            ans += total;
        }
    }

    return ans;
}

// complexity: O(N)
llt get_sum_of_subarrays_3(vector<llt> &v, llt size)
{
    llt ans = 0, total = 0;

    for (llt i = 0; i < size; i++)
    {
        total = ((((i + 1) % mod) * ((size - i) % mod)) % mod) * v[i] % mod;
        ans = (ans % mod + total % mod) % mod;
    }

    return ans;
}

int main(int argc, char const *argv[])
{
    vector<llt> v = scan_vector<llt>();

    cout << get_sum_of_subarrays(v, v.size()) << endl;

    cout << get_sum_of_subarrays_2(v, v.size()) << endl;

    cout << get_sum_of_subarrays_3(v, v.size()) << endl;

    return 0;
}