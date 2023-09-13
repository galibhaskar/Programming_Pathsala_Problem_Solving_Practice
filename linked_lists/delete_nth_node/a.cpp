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

    void deleteNthNodeFromLastInLinkedList(int n)
    {
        Node *firstPtr, *secondPtr, *temp;

        if (head != NULL)
            firstPtr = head;

        temp = head;

        // moving temp to n positions
        while (temp != NULL && n > 0)
        {
            temp = temp->next;
            n--;
        }

        if (temp == NULL)
        {
            if (n == 0)
            {
                head = firstPtr->next;

                cout << "deleted node is:" << firstPtr->data << endl;

                delete firstPtr;
            }

            else
                cout << "nth node is out of range" << endl;
        }

        else
        {
            // initializing the secondptr after n positions
            // such that firstPtr and secondPtr at n units distance
            secondPtr = temp;

            while (secondPtr != NULL && secondPtr->next != NULL)
            {
                secondPtr = secondPtr->next;
                firstPtr = firstPtr->next;
            }

            Node *node_to_delete = firstPtr->next;

            cout << "deleting node:" << node_to_delete->data << endl;

            firstPtr->next = node_to_delete->next;

            delete node_to_delete;
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

    int n;

    cin >> n;

    s.deleteNthNodeFromLastInLinkedList(n);

    return 0;
}