#include <bits/stdc++.h>

using namespace std;

// count the min no of swaps which bring all the elements <=range together.
int get_min_swaps(vector<int> arr, int range)
{
    int total_legal_elements = 0;

    for (auto i : arr)
        if (i <= range)
            total_legal_elements++;

    int subarray_size = total_legal_elements;

    int index = 0, count = 0, max_legal_count = INT_MIN;

    while (index < subarray_size)
        if (arr[index++] <= range)
            count++;

    max_legal_count = max(max_legal_count, count);

    while (index < arr.size())
    {
        if (arr[index - subarray_size] <= range)
            count--;

        if (arr[index] <= range)
            count++;

        max_legal_count = max(max_legal_count, count);

        index++;
    }

    return total_legal_elements - max_legal_count;
}

// count the frequency of x in each subarray of size k
vector<int> get_freq_of_x_in_k_subarray(vector<int> arr, int k, int x)
{
    vector<int> freq_array;

    int i = 0, freq_count = 0;

    while (i != k)
        if (arr[i++] == x)
            freq_count++;

    freq_array.push_back(freq_count);

    while (i < arr.size())
    {
        if (arr[i - k] == x)
            freq_count--;

        if (arr[i] == x)
            freq_count++;

        freq_array.push_back(freq_count);

        i++;
    }

    return freq_array;
}

vector<int> get_subarray_sums(vector<int> arr, int k)
{
    vector<int> subarray_sum;

    int total_value = 0, i = 0;

    while (i != k)
        total_value += arr[i++];

    subarray_sum.push_back(total_value);

    // cout << "total:" << total_value << endl;

    while (i < arr.size())
    {
        total_value = total_value - arr[i - k] + arr[i];
        // cout << "total:" << total_value << endl;
        subarray_sum.push_back(total_value);
        i++;
    }

    return subarray_sum;
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

template <typename T>
void print_vector(vector<T> arr)
{
    cout << "-------vector begin-----" << endl;

    for (auto ele : arr)
        cout << ele << " ";

    cout << "-------vector end-----" << endl;
}

int main(int argc, char const *argv[])
{
    vector<int> v = scan_vector<int>();

    // // subarray size
    // int k;

    // cin >> k;

    // print_vector<int>(get_subarray_sums(v, k));

    // element to find the frequency
    // int x;

    // cin >> x;

    // print_vector<int>(get_freq_of_x_in_k_subarray(v, k, x));

    // elements <=range
    int range;

    cin >> range;

    cout << get_min_swaps(v, range);

    return 0;
}