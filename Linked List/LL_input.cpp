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

void printLL(Node *head)
{
    Node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

Node *takeInput_Better()
{
    int data;
    cin >> data;
    Node *head = NULL;
    Node*tail = NULL; 
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
           //OR
        //    tail = n;
        }

        cin >> data;
    }
    return head;
}

int main()
{
    Node *head = takeInput_Better();
    printLL(head);
}