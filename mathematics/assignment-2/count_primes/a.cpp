#include <bits/stdc++.h>
#define range 1000000

using namespace std;

class Solution
{
public:
    void compute_pre_processing(vector<int> &psum, int num)
    {
        vector<bool> v(range + 1, 1);

        v[0] = v[1] = 0;

        for (int i = 2; i * i <= num; i++)
        {
            if (v[i])
                for (int j = i * i; j <= num; j += i)
                    if (v[j])
                        v[j] = 0;
        }

        psum[0] = v[0];

        for (int i = 1; i <= num; i++)
            psum[i] = v[i] + psum[i - 1];
    }
};

int main(int argc, char const *argv[])
{

    int test_cases, n;

    Solution s;

    cin >> test_cases;

    vector<int> psum(range + 1);

    s.compute_pre_processing(psum, range);

    while (test_cases--)
    {
        cin >> n;

        cout << psum[n] << endl;
    }

    return 0;
}