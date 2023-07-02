#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    struct Node
    {
        char ch;
        int frequency;
        Node *left;
        Node *right;

        Node(char c, int f, Node *l = NULL, Node *r = NULL)
        {
            ch = c;
            frequency = f;
            left = l;
            right = r;
        }
    };

    struct cmp
    {
        bool operator()(Node *a, Node *b)
        {
            return a->frequency > b->frequency;
        }
    };

    void get_codes(string byte_code, vector<string> &result, Node *node)
    {
        if (node == NULL)
            return;

        if (node->left == NULL && node->right == NULL)
        {
            // cout << "char:" << node->ch << " fre:" << node->frequency << endl;

            // cout << "code:" << byte_code << endl;

            result.push_back(byte_code);
            return;
        }

        get_codes(byte_code + '0', result, node->left);

        get_codes(byte_code + '1', result, node->right);
    }

    vector<string> huffmanCodes(string S, vector<int> f, int N)
    {
        priority_queue<Node *, vector<Node *>, cmp> huffman_tree;

        // creating all leaf nodes in the priority queue
        for (int i = 0; i < N; i++)
            huffman_tree.push(new Node(S[i], f[i]));

        while (huffman_tree.size() > 1)
        {
            Node *a = huffman_tree.top();
            huffman_tree.pop();

            // cout << "Node a:" << a->ch << " freq:" << a->frequency << endl;

            Node *b = huffman_tree.top();
            huffman_tree.pop();
            // cout << "Node b:" << b->ch << " freq:" << b->frequency << endl;

            huffman_tree.push(new Node('a', a->frequency + b->frequency, a, b));
        }

        string byte_code = "";

        vector<string> result;

        get_codes(byte_code, result, huffman_tree.top());

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

int main(int argc, char const *argv[])
{
    Solution s;

    string str = "abcdef";

    vector<int> frequency{5, 9, 12, 13, 16, 45};

    print_vector<string>(s.huffmanCodes(str, frequency, str.length()));

    return 0;
}