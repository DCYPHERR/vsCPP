//NOT WORKING
#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};

void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

Node *insert()
{
    int data;
    cin >> data;
    Node *head = NULL;
    Node *tail = NULL;
    while (data != -1)
    {
        Node *n = new Node(data);
        if (head == NULL)
        {
            head = n;
            tail = n;
        }
        else
        {
            tail->next = n;
            tail = tail->next;
        }
        cin >> data;
    }
    return head;
}

int getCount(Node *head)
{
    if (head == NULL)
    {
        return 0;
    }
    else
    {
        return (1 + getCount(head->next));
    }
}

int getN_node(Node *head, int i)
{
    Node *temp = head;
    int count;
    count = 0;
    while (temp != NULL)
    {
        if (count == i)
        {
            return temp->data;
        }
        temp = temp->next;
        count++;
    }
    return temp->data;
}

Node *mergeUtil(Node *h1, Node *h2)
{
    if (!h1->next)
    {
        h1->next = h2;
        return h1;
    }

    Node *t1 = h1;
    Node *t2 = h2;
    Node *n1 = h1->next;
    Node *n2 = h2->next;

    while (n1 && t2)
    {

        if ((t2->data) >= (t1->data) && (t2->data) <= (n1->data))
        {
            n1 = t2->next;
            t1->next = t2;
            t2->next = n1;

            t1 = t2;
            t2 = n2;
        }
        else
        {

            if (n1->next)
            {
                n1 = n1->next;
                t1 = t1->next;
            }

            else
            {
                n1->next = t2;
                return h1;
            }
        }
    }
    return h1;
}

Node *mergeSortedLL(Node *h1, Node *h2)
{
    Node *fHead = NULL;
    Node *fTail = NULL;

    {
        if (!h1)
            return h2;
        if (!h2)
            return h1;

        if (h1->data < h2->data)
            return mergeUtil(h1, h2);
        else
            return mergeUtil(h2, h1);
    }
}

int main()
{
    Node *h1 = insert();
    print(h1);
    cout << endl;

    Node *h2 = insert();
    print(h2);
    cout << endl;

    Node *Final = mergeSortedLL(h1, h2);
    print(Final);
    return 0;
}