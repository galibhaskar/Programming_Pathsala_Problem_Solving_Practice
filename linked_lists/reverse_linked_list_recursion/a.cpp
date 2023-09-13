#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int data;

    struct Node *next;

    Node(int x, Node *link)
    {
        data = x;
        next = link;
    }
};

class Solution
{
public:
    Node *head;

    Solution()
    {
        head = NULL;
    }

    Node *reverseLinkedList(Node *currNode)
    {
        if (currNode == NULL || currNode->next == NULL)
            return currNode;

        // delinking the current node;
        Node *temp = currNode->next;

        currNode->next = NULL;

        // invoking recursion on remaining part
        Node *newHead = reverseLinkedList(temp);

        // linking back to separate code
        temp->next = currNode;

        return newHead;
    }

    void recReverseLinkedList()
    {
        head = reverseLinkedList(head);
    }

    void printLinkedList()
    {
        Node *temp = head;

        while (temp != NULL)
        {
            cout << "data:" << temp->data << endl;
            temp = temp->next;
        }
    }

    void insertIntoLinkedList(int data)
    {
        Node *newNode = new Node(data, NULL);

        if (head == NULL)
            head = newNode;

        else
        {
            Node *temp = head;

            while (temp->next != NULL)
                temp = temp->next;

            temp->next = newNode;
        }
    }
};

int main(int argc, char const *argv[])
{
    Solution s;

    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    for (int i : arr)
        s.insertIntoLinkedList(i);

    s.recReverseLinkedList();

    s.printLinkedList();

    return 0;
}