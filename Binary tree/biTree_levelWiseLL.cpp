#include <iostream>
#include <queue>
#include <vector>
using namespace std;
template <typename T>
class BinaryTreeNode
{
public:
    T data;
    BinaryTreeNode<int> *left;
    BinaryTreeNode<int> *right;
    BinaryTreeNode(T data)
    {
        this->data = data;
        left = right = NULL;
    }

    ~BinaryTreeNode()
    {
        delete left;
        delete right;
    }
};

template <typename T>
class Node
{
public:
    T data;
    Node *next;
    Node(T data)
    {
        this->data = data;
        next = NULL;
    }
};

BinaryTreeNode<int> *takeInput()
{
    int rootData;
    cout << "Enter root : ";
    cin >> rootData;
    if(rootData == -1)
    {
        return NULL;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int> *> pendingBinaryNode;
    pendingBinaryNode.push(root);
    while(pendingBinaryNode.size() != 0)
    {
        BinaryTreeNode<int> *front = pendingBinaryNode.front();
        pendingBinaryNode.pop();
        int leftChildData;
        cout <<"Enter left child of : " << front->data << " : ";
        cin >> leftChildData;
        if(leftChildData != -1)
        {
            BinaryTreeNode<int> *child = new BinaryTreeNode<int>(leftChildData);
            front->left = child;
            pendingBinaryNode.push(child);
        }
        int rightChildData;
        cout <<"Enter right child of : " << front->data << " : ";
        cin >> rightChildData;
        if(rightChildData != -1)
        {
            BinaryTreeNode<int> *child = new BinaryTreeNode<int>(rightChildData);
            front->right = child;
            pendingBinaryNode.push(child);
        }
    }
    cout << endl;
    return root;
}

void print(BinaryTreeNode<int> *root)
{
    if(root == NULL)
    {
        return;
    }

    queue<BinaryTreeNode<int> *> check;
    check.push(root);
    while(check.size() != 0)
    {
        BinaryTreeNode<int> *front = check.front();
        cout << front->data << " : ";
        check.pop();

        if(root->left != NULL)
        {
            cout << "L : " << front->left->data << " , ";
            check.push(root->left);
        }
        else
        {
            cout << "L : " << "-1 " << " , ";
        }

        if(root->right != NULL)
        {
            cout << "R : " << front->right->data << " , ";
            check.push(front->right);
        }
        else
        {
            cout << "R : " << "-1 " << " , ";
        }
        cout << endl;
        root = check.front();
    }
}


vector<Node<int> *> createLLforEachlvl(BinaryTreeNode<int> *root)
{
    queue<BinaryTreeNode<int> *> poke;
    poke.push(root);
    
    int currLvlRemaining = 1;
    int nextLvlCount = 0;
    vector<Node<int> *> output;
    Node<int> *currLvlHead;
    Node<int> *currLvlTail;
    currLvlHead = currLvlTail = NULL;
    while(poke.size() != 0)
    {
        BinaryTreeNode<int> *front = poke.front();
        poke.pop();
        Node<int> *newN = new Node<int>(front->data);
        if(currLvlHead == NULL)
        {
            currLvlHead = newN;
            currLvlTail = newN;
        }
        else
        {
            currLvlTail->next = newN;
            currLvlTail = newN;
        }
        if(front->left != NULL)
        {
            poke.push(front->left);
            nextLvlCount++;
        }
        if(front->right != NULL)
        {
            poke.push(front->right);
            nextLvlCount++;
        }
        currLvlRemaining--;
        if(currLvlRemaining == 0)
        {
            output.push_back(currLvlHead);
            currLvlHead = NULL;
            currLvlTail = NULL;
            currLvlRemaining = nextLvlCount;
            nextLvlCount = 0;
        }
    }
    return output;
}


int main()
{
    BinaryTreeNode<int> *root = takeInput();
    cout << endl;
    print(root);
    cout << endl;
    createLLforEachlvl(root);
    cout << endl;
    delete root;
    return 0;
}