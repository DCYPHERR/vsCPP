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
    int count = 0;
    while (temp != NULL)
    {
        if (count == i)
        {
            return (temp->data);
        }
        count++;
        temp = temp->next;
    }
    return temp->data;
}

void medianNode(Node *head)
{
    int length = getCount(head);
    if (length % 2 == 0)
    {
        int Node_index = (length - 1) / 2;
        cout << getN_node(head, Node_index);
    }
    else
    {
        int Node_index = (length - 1) / 2;
        cout << getN_node(head, Node_index);
    }
}

int main()
{
    Node *head = insert();
    print(head);
    cout << endl;

    medianNode(head);
    return 0;
}