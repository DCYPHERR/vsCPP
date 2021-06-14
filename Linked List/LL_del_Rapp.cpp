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
    while(temp!=NULL){
    cout << temp->data << " ";
    temp = temp->next;
    }
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

Node *insert()
{
    int data;
    cin >> data;
    Node *head = NULL;
    Node *tail = NULL;
    while(data!=-1) 
    {
        Node *n = new Node(data);

        if(head == NULL)
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

Node *deleteR(Node* head, int i) 
{   
    Node *prev = NULL;
    Node *ptr = head;
    
    int pos = 0;
    
    if(i==0)
    {
        head=head->next;
        delete (ptr);
    }
    else
    {
        while(i!=pos)
        {
            ++pos;
            prev=ptr;
            ptr=ptr->next;
        }
        
        if(ptr!=NULL)
        {
            prev->next=ptr->next;
            delete (ptr);
        }
    }
    return head;
}


int main()
{
    Node *head = insert();
    print(head);    
    int i;
    cin >> i;
    deleteR(head, i);
    print(head);
    return 0;
}