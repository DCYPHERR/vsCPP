#include <iostream>
#include <queue>
using namespace std;
template <typename T>
class BinaryTreeNode
{
    public:
    T data;
    BinaryTreeNode *left;
    BinaryTreeNode *right;

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

BinaryTreeNode<int> *takeInput()
{
    int rootData;
    cout << "Enter Root : ";
    cin >> rootData;
    if(rootData == NULL)
    {
        return NULL;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode <int> *> pendingBinaryNode;
    pendingBinaryNode.push(root);
    while (pendingBinaryNode.size() != 0)
    {
        BinaryTreeNode<int> *front = pendingBinaryNode.front();
        pendingBinaryNode.pop();
        int leftChildData;
        cout << "Enter Left child of " << front->data << " : ";
        cin >> leftChildData;
        if(leftChildData != -1)
        {
            BinaryTreeNode<int> *child = new BinaryTreeNode<int>(leftChildData);
            front->left = child;
            pendingBinaryNode.push(child);
        }
        int rightChildData;
        cout << "Enter Right child of " << front->data << " : ";
        cin >> rightChildData;
        if(rightChildData != -1)
        {
            BinaryTreeNode<int> *child = new BinaryTreeNode<int>(rightChildData);
            front->right = child;
            pendingBinaryNode.push(child);
        }
    }
    return root;
    cout << endl;
}

void preOrder(BinaryTreeNode<int> *root)
{
    if(root == NULL)
    {
        return;
    }

    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

int main()
{
    BinaryTreeNode<int> *root = takeInput();
    cout << endl;
    preOrder(root);
    delete root;
    return 0;
}