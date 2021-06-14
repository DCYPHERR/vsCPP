//FUCKED Not Working
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
    while (temp != NULL)
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
Node *insertIposR(Node *head, int i, int data)
{
    Node *n = new Node(data);
    Node *temp = head;
    int count = 0;
    //Base case
    if (head == NULL)
    {
        return head;
    }

    if (i == 0)
    {   
        n->next = head;
        head = n;
        
        return head;
    }
    while(temp != NULL && count < i - 1) {
		temp = temp -> next;
		count++;
	}
	if(temp != NULL) {
		Node *a = temp -> next;
		temp -> next = n;
		n -> next = a;
	}
	return head;
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
int main()
{
    Node *head = insert();
    print(head);
    cout << endl;
    cout << "Number of nodes is : " << getCount(head) << endl;
    int choice, data;
    cout << "Enter the index to insert the node : ";
    cin >> choice;
    cout << endl;
    cout << "Enter the data of the node : ";
    cin >> data;
    cout << endl;
    insertIposR(head, choice, data);
    print(head);
    return 0;
}