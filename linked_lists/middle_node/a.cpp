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
private:
    Node *head;

public:
    Solution()
    {
        head = NULL;
    }

    int getLengthOfLinkedList()
    {
        int counter = 0;

        Node *temp = head;

        while (temp != NULL)
        {
            temp = temp->next;
            counter++;
        }

        return counter;
    }

    void findMiddleNode()
    {
        int linked_list_length = getLengthOfLinkedList();

        int hops = linked_list_length / 2;

        Node *temp = head;

        while (hops > 0)
        {
            temp = temp->next;
            hops--;
        }

        cout << temp->data << endl;
    }

    void slowAndFastPointerApproach()
    {
        Node *fast = head, *slow = head;

        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;

            fast = fast->next->next;
        }

        cout << "middle node:" << slow->data << endl;
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

    vector<int> arr = {1, 2, 3, 4, 5};

    for (int i : arr)
        s.insertIntoLinkedList(i);

    s.findMiddleNode();

    s.slowAndFastPointerApproach();

    return 0;
}