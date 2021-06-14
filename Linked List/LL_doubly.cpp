#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    Node(int data)
    {
        this->data = data;
        next = NULL;
        prev = NULL;
    }
};

void insertHead(Node *&head, int data)
{
    Node *n = new Node(data);
    n->next = head;
    if (head != NULL)
    {
        head->prev = n;
    }
    head = n;
}

void insertTail(Node *&head, int data)
{
    if (head == NULL)
    {
        insertHead(head, data);
        return;
    }

    Node *n = new Node(data);
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
    n->prev = temp;
}

void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

void deleteHead(Node* &head)
{
    Node *temp = head;
    head = head->next;
    head->prev = NULL;
    delete temp;
}

void deleteNode(Node *&head, int i)
{

    if(i==1)
    {
        deleteHead(head);
        return;
    }
    Node *temp = head;
    int count = 1;
    while (temp != NULL && count != i)
    {
        temp = temp->next;
        count++;
    }

    temp->prev->next = temp->next;
    if (temp->next != NULL)
    {
        temp->next->prev = temp->prev;
    }

    delete temp;
}

int main()
{
    Node *head = NULL;
    insertTail(head, 5);
    insertTail(head, 1);
    insertTail(head, 2);
    insertTail(head, 3);
    insertTail(head, 4);
    print(head);
    cout << endl;
    insertHead(head, 10);
    print(head);
    deleteNode(head,1);
    cout << endl;
    print(head);

    return 0;
}