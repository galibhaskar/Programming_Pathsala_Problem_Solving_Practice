#include <bits/stdc++.h>

using namespace std;

template <typename T>
void print_2d_vector(vector<vector<T>> &arr)
{
    cout << "-------vector begin-----" << endl;

    for (auto ele : arr)
    {
        for (auto item : ele)
            cout << item << " ";
        cout << endl;
    }

    cout << "-------vector end-----" << endl;
}

void rotate_image(vector<vector<int>> &v, int size)
{
    for (int i = 0; i < size / 2; i++)
        swap(v[i], v[size - i - 1]);

    // print_2d_vector(v);

    for (int i = 0; i < size; i++)
        for (int j = i + 1; j < size; j++)
            swap(v[i][j], v[j][i]);
}

int main(int argc, char const *argv[])
{
    int n;

    cin >> n;

    vector<vector<int>> v(n);

    int val;

    for (int i = 0; i < n; i++)
    {
        vector<int> temp(n);

        for (int j = 0; j < n; j++)
        {
            cin >> val;
            temp[j] = val;
        }

        v[i] = temp;
    }

    rotate_image(v, v.size());

    print_2d_vector<int>(v);

    return 0;
}