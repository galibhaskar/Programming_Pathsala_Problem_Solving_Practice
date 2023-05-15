#include <bits/stdc++.h>

using namespace std;

typedef long long int ut;

ut get_rain_water_stored(ut n, vector<ut> heights)
{
    vector<ut> pmax(n, 0), smax(n, 0);

    pmax[0] = heights[0];

    smax[n - 1] = heights[n - 1];

    ut rain_water_quantity = 0;

    for (ut i = 1; i < n; i++)
    {
        pmax[i] = max(pmax[i - 1], heights[i]);
        smax[n - i - 1] = max(smax[n - i], heights[n - i - 1]);
    }

    for (ut i = 1; i < n-1; i++)
	{
		ut amount = min(pmax[i], smax[i]) - heights[i];
		if(amount>0)
        	rain_water_quantity += amount;
	}

    return rain_water_quantity;
}

template <typename T>
vector<T> scan_vector()
{
    vector<T> arr;

    ut n;

    cin >> n;

    T input;

    while (n--)
    {
        cin >> input;
        arr.push_back(input);
    }

    return arr;
}

int main(int argc, char const *argv[])
{
    vector<ut> v = scan_vector<ut>();

    cout << get_rain_water_stored(v.size(), v) << endl;

    return 0;
}