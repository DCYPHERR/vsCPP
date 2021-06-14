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

int getN_node(Node *head, int i)
{
    Node *temp = head;
    int count = 0;
    while(temp!=NULL)
    {
        if(count == i)
        {
            return temp->data;
        }
        count++;
        temp = temp->next;
    }
    return temp->data;
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

int getCount(Node *head)
{
    if(head == NULL)
    {
        return 0;
    }
    else 
    {
        return (1+getCount(head->next));
    }
}

void medianNode(Node *head)
{
    Node *slow = head;
    Node *fast = head->next;


    
    if (head!=NULL){
        while(fast!=NULL && fast->next!=NULL) 
        {
        slow = slow->next;
        fast = fast->next->next;
        }
        cout << "The middle element is " << slow->data; 
    } 
}

int main()
{
    Node *head = insert();
    print(head);
    cout << endl;
    cout << "Number of Nodes is : " << getCount(head) << endl;
    medianNode(head);
    return 0;
}