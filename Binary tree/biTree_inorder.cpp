//http://cslibrary.stanford.edu/110/BinaryTrees.pdf
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

BinaryTreeNode<int> *takeInputLevelwise()
{
    int rootData;
    cout << "Enter Root Data : ";
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
        int leftChildData;
        cout << "Enter Left Child of " << front->data << " : ";
        cin >> leftChildData;
        if (leftChildData != -1)
        {
            BinaryTreeNode<int> *child = new BinaryTreeNode<int>(leftChildData);
            pendingBinaryNode.push(child);
            front->left = child;
        }
        cout << "Enter Right Child of " << front->data << " : ";
        int rightChildData;
        cin >> rightChildData;
        if (rightChildData != -1)
        {
            BinaryTreeNode<int> *child = new BinaryTreeNode<int>(rightChildData);
            pendingBinaryNode.push(child);
            front->right = child;
        }
    }
    return root;
    cout << endl;
}

void printInOrder(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }

    printInOrder(root->left);
    cout << root->data << " ";
    printInOrder(root->right);
}

int main()
{
    BinaryTreeNode<int> *root = takeInputLevelwise();
    cout << endl;
    printInOrder(root);

    return 0;
}