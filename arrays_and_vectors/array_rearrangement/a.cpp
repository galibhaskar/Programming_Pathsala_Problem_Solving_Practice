#include <bits/stdc++.h>

using namespace std;

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

template <typename T>
void print_vector(vector<T> arr)
{
    cout << "-------vector begin-----" << endl;

    for (auto ele : arr)
        cout << ele << " ";

    cout << "-------vector end-----" << endl;
}

void arrange_elements_in_cycle(vector<int> &v, int start_index, int index)
{
    int element = v[index];

    if (element != start_index)
        arrange_elements_in_cycle(v, start_index, v[index]);

    v[element] = -(index + 1);
}

void rearrange_vector(vector<int> &v)
{
    for (auto i = 0; i < v.size(); i++)
    {
        if (v[i] > 0)
            arrange_elements_in_cycle(v, i, i);
    }

    for (auto i = 0; i < v.size(); i++)
        v[i] = -(v[i] + 1);
}

void rearrange_vector_alternate_solution(vector<int> &v)
{
    int old_value, new_value, size = v.size();

    for (int i = 0; i < size; i++)
    {
        old_value = v[i] % size;
        v[old_value] = size * i + v[old_value];
    }

    for (int i = 0; i < size; i++)
        v[i] /= size;
}

int main(int argc, char const *argv[])
{

    vector<int> v = scan_vector<int, int>();

    // rearrange_vector(v);

    rearrange_vector_alternate_solution(v);

    print_vector<int>(v);

    return 0;
}