#include <iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node *next;
    Node (int data)
    {
        this->data = data;
        next = NULL;
    }
};

void insertHead(Node* &head, int data)
{
    Node *n = new Node(data);
    if(head==NULL)
    {
        n->next = n;
        head = n;
        return;
    }
    Node *temp = head;
    while(temp->next!=head)
    {
        temp = temp->next;
    }
    temp->next = n;
    n->next = head;
    head = n;
}

void insertTail(Node* &head, int data)
{   
    if(head==NULL)
    {
        insertHead(head, data);
        return;
    }
    Node *n = new Node(data);
    Node * temp = head;
    while(temp->next!=head)
    {
        temp = temp->next;
    }
    temp->next = n;
    n->next = head;
}

void deleteHead(Node* &head)
{
    Node *temp = head;
    while(temp->next!=head)
    {
        temp = temp->next;
    }
    Node *todel = head;
    temp->next = head->next;
    head = head->next;
    delete todel;
}

void deletetion(Node* &head, int i)
{   
    if(i==1)
    {
        deleteHead(head);
        return;
    }
    Node *temp = head;
    int count = 1;
    while(count!=i-1)
    {
        temp = temp->next;
        count++;
    }
    Node *todel = temp->next;
    temp->next = temp->next->next;
    delete todel;
}

void print(Node *head)
{
    Node *temp = head;
    do
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    while(temp!=head);
    cout << endl;
}

int main()
{
    Node *head = NULL;
    insertTail(head,1);
    insertTail(head,2);
    insertTail(head,3);
    insertTail(head,4);
    insertTail(head,5);
    insertTail(head,6);
    insertTail(head,7);
    print(head);
    insertHead(head, 5);
    print(head);
    deletetion(head,1);
    print(head);
    return 0;
}