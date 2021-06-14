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

void print(Node *head)
{
    Node *temp = head;
    while(temp!=NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int getCount(Node *head)
{
    if(head == NULL)
    {
        return 0;
    }
    else 
    {
        return(1+getCount(head->next));
    }
}

int getN_node (Node *head, int i)
{
    Node *temp = head;
    int count;
    count = 0;
    while(temp!=NULL)
    {
        if(count == i)
        {
            return temp->data;
        }
        temp = temp->next;
        count++;
    }
    return temp->data;
}

Node *rev_LL(Node *head)
{
    Node *current = head;
    Node *next = NULL;
    Node *prev = NULL;
    while(current!=NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
    
    return head;
}


int main()
{
    Node *head = insert();
    print(head);
    cout << endl;
    cout <<"After reversing : " << endl;
    head = rev_LL(head);
    print(head);
    return 0;
}