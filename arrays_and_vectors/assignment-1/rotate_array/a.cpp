#include <bits/stdc++.h>

using namespace std;

typedef long long int llt;

template <typename T>
void print_vector(vector<T> arr)
{
    cout << "-------vector begin-----" << endl;

    for (auto ele : arr)
        cout << ele << " ";

    cout << "-------vector end-----" << endl;
}

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

void get_rotated_array(vector<llt> &v, llt n, llt k)
{
    if (k >= n)
        k %= n;

    cout << "k:" << k << " n: " << n << endl;

    if (k == 0)
        return;

    // reversing the entire array using swapping
    for (llt i = 0; i < n / 2; i++)
        swap(v[i], v[n - i - 1]);

    print_vector(v);

    // reversing the first k elements using swapping
    for (llt i = 0; i < k / 2; i++)
    {
        swap(v[i], v[k - i - 1]);

        print_vector(v);
    }

    // reversing the remaining elements using swapping
    for (llt i = 0; i < (n - k) / 2; i++)
    {
        swap(v[k + i], v[n - i - 1]);
        print_vector(v);
    }
}

int main(int argc, char const *argv[])
{
    vector<llt> v = scan_vector<llt>();

    llt k;

    cin >> k;

    get_rotated_array(v, v.size(), k);

    print_vector<llt>(v);

    return 0;
}