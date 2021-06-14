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
    while(temp!=NULL)
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
    while(data!=-1)
    {
        Node *n = new Node(data);
        if(head==NULL)
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
    if(head==NULL)
    {
        return 0;
    }
    else 
    {
        return (1+getCount(head->next));
    }
}

int main()
{
    Node *head = insert();
    print(head);
    cout << endl;
    cout << "Number of nodes is : " << getCount(head);
    return 0;
}