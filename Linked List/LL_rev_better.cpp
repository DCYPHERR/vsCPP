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

void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

// Node *rev_LL(Node *head)
// {
//     if(head == NULL || head->next==NULL)
//     {
//         return head;
//     }

//     Node *smallAns = rev_LL(head->next);
//     Node *temp = smallAns;
//     while(temp->next != NULL)
//     {
//         temp = temp->next;
//     }
//     temp->next = head;
//     head->next = NULL;
//     return smallAns;
// }

Pair rev_Better(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        Pair ans;
        ans.head = head;
        ans.tail = head;
        return ans;
    }

    Pair smallAns = rev_Better(head->next);

    smallAns.tail->next = head;
    head->next = NULL;
    Pair ans;
    ans.head = smallAns.head;
    ans.tail = head;
    return ans;
}

Node *reversal(Node *head)
{
    return rev_Better(head).head;
}

int main()
{
    Node *head = insert();
    print(head);
    cout << endl;
    // head = rev_LL(head);
    head = reversal(head);
    print(head);
    return 0;
}