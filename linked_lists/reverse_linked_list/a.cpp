#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int data;

    struct Node *next;

    Node(int d, struct Node *link)
    {
        data = d;
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

    void reverseLinkedList()
    {
        Node *prevPtr = NULL, *currPtr = head, *tempPtr;

        if (head == NULL)
            cout << "no nodes" << endl;

        currPtr = head;

        while (currPtr != NULL)
        {
            // cout << "curr:" << currPtr->data << endl;
            tempPtr = currPtr->next;
            currPtr->next = prevPtr;
            prevPtr = currPtr;
            currPtr = tempPtr;
        }

        head = prevPtr;
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

    s.reverseLinkedList();

    s.printLinkedList();

    return 0;
}