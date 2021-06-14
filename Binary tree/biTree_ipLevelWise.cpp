#include <iostream>
#include <queue>
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

void print(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << "\n";
    cout << root->data << " : ";
    if (root->left != NULL)
    {
        cout << "L" << root->left->data;
    }
    cout << "\t";
    if (root->right != NULL)
    {
        cout << "R" << root->right->data;
    }

    print(root->left);
    print(root->right);
}

BinaryTreeNode<int> *takeInputBetter()
{
    int rootData;
    cout << "Enter root data : ";
    cin >> rootData;
    if (rootData == -1)
    {
        return NULL;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int> *> pendingBinaryNode;
    pendingBinaryNode.push(root);
    while (pendingBinaryNode.size() != 0)
    {
        BinaryTreeNode<int> *front = pendingBinaryNode.front();
        pendingBinaryNode.pop();
        cout << "Enter Left child of " << front->data << " : ";
        int leftChildData;
        cin >> leftChildData;
        if (leftChildData != -1)
        {
            BinaryTreeNode<int> *child = new BinaryTreeNode<int>(leftChildData);
            front->left = child;
            pendingBinaryNode.push(child);
        }
        cout << "Enter Right child of " << front->data << " : ";
        int rightChildData;
        cin >> rightChildData;
        if (rightChildData != -1)
        {
            BinaryTreeNode<int> *child = new BinaryTreeNode<int>(rightChildData);
            front->right = child;
            pendingBinaryNode.push(child);
        }
    }
    return root;
}

int main()
{
    BinaryTreeNode<int> *root = takeInputBetter();
    print(root);
    return 0;
}