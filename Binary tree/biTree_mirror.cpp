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
        left = NULL;
        right = NULL;
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
    cout << "Enter root : ";
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
        cout << "Enter left child of " << front->data << " : ";
        cin >> leftChildData;
        if (leftChildData != -1)
        {
            BinaryTreeNode<int> *child = new BinaryTreeNode<int>(leftChildData);
            front->left = child;
            pendingBinaryNode.push(child);
        }
        int rightChildData;
        cout << "Enter right child of " << front->data << " : ";
        cin >> rightChildData;
        if (rightChildData != -1)
        {
            BinaryTreeNode<int> *child = new BinaryTreeNode<int>(rightChildData);
            front->right = child;
            pendingBinaryNode.push(child);
        }
    }
    return root;
    cout << endl;
}

void printLevelWise(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }

    queue<BinaryTreeNode<int> *> check;
    check.push(root);
    while (check.size() != 0)
    {
        BinaryTreeNode<int> *front = check.front();
        cout << front->data << " : ";
        check.pop();

        if (root->left != NULL)
        {
            cout << "L: " << root->left->data << " , ";
            check.push(root->left);
        }
        else
        {
            cout << "L: "
                 << "-1 "
                 << " , ";
        }

        if (root->right != NULL)
        {
            cout << "R: " << root->right->data << " , ";
            check.push(root->right);
        }
        else
        {
            cout << "R: "
                 << "-1 "
                 << " , ";
        }

        cout << endl;
        root = check.front();
    }
}

void mirror(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }

    BinaryTreeNode<int> *p;
    mirror(root->left);
    mirror(root->right);

    p = root->left;
    root->left = root->right;
    root->right = p;
}

int main()
{
    BinaryTreeNode<int> *root = takeInput();
    cout << endl;
    printLevelWise(root);
    cout << endl;
    mirror(root);
    printLevelWise(root);
    cout << endl;
    delete root;
    return 0;
}