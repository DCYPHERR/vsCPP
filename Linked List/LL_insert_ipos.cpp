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

void print_LL(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

Node *takeinput()
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

Node *insert_Node(Node *head, int i, int data)
{
    Node *n = new Node(data);
    Node *temp = head;

    int count = 0;
    if (i == 0)
    {
        n->next = head;
        head = n;
        return head;
    }
    while (temp != NULL && count < i - 1)
    {
        temp = temp->next;
        count++;
    }

    if (temp != NULL)
    {

        Node *a = temp->next;
        temp->next = n;
        n->next = a;
    }
    return head;
}

int main()
{

    Node *head = takeinput();
    print_LL(head);
    int i, data;
    cin >> i >> data;
    head = insert_Node(head, i, data);
    print_LL(head);
    return 0;
}
