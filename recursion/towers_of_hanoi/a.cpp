#include <bits/stdc++.h>

using namespace std;

class Solution
{

public:
    vector<int> towers_of_hanoi(int src, int dest, int intermediate, int plates, int &moves)
    {
        if (moves == 0)
            return vector<int>{};

        if (plates == 1)
        {
            moves--;

            // if (moves == 0)
            //     cout << src << " " << dest << endl;

            return vector<int>{src, dest};
        }

        // step -1
        towers_of_hanoi(src, intermediate, dest, plates - 1, moves);

        // step-2
        if (moves)
            towers_of_hanoi(src, dest, intermediate, 1, moves);

        // step-3
        if (moves)
            towers_of_hanoi(intermediate, dest, src, plates - 1, moves);
    }

    vector<int> shiftPile(int N, int n)
    {
        return towers_of_hanoi(1, 3, 2, N, n);
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

int main(int argc, char const *argv[])
{

    Solution s;

    print_vector<int>(s.shiftPile(2, 2));

    return 0;
}