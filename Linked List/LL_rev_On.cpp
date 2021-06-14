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

class Pair
{
    public:
    Node *head;
    Node *tail;
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

Node *reverse_LL(Node *head)
{
    if(head==NULL || head->next==NULL)
    {
        return head;
    }

    Node *smallAns = reverse_LL(head->next);
    
    Node *tail = head->next;
    tail -> next = head;
    head->next = NULL;
    return smallAns;
}

int main()
{
    Node *head = insert();
    print(head);
    cout << endl;
    cout <<"After reversing : "<< endl;
    head = reverse_LL(head);
    print(head);
    return 0;
}