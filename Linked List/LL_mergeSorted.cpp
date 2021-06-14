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
    while(data != -1)
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

int getN_node(Node *head, int i)
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
        count ++;
    }
    return temp->data;
}

int getCount(Node *head)
{
    if(head == NULL)
    {
        return 0;
    }
    else {
        return (1+getCount(head->next));
    }
}

Node *mergeSortedLL(Node *h1, Node *h2)
{
    // Node *fHead = NULL;
    // Node *fTail = NULL;
    if (!h1)
        return h2;
    if (!h2)
        return h1;
  
    
    if (h1->data < h2->data) {
        h1->next = mergeSortedLL(h1->next, h2);
        return h1;
    }
    else {
        h2->next = mergeSortedLL(h1, h2->next);
        return h2;
    }
}

int main()
{
    Node *head1 = insert();
    print(head1);
    cout << endl;

    Node*head2 = insert();
    print(head2);
    cout << endl;
    
    Node* mergedhead = mergeSortedLL(head1, head2);
    print(mergedhead);
    return 0;
}