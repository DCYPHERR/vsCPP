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

void printLevelWise(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return;

    queue<BinaryTreeNode<int> *> check;
    check.push(root);
    while (check.size() != 0)
    {
        BinaryTreeNode<int> *p = check.front();
        cout << p->data << " : ";
        check.pop();

        if (root->left != NULL)
        {
            cout << "L:" << root->left->data << " , ";
            check.push(root->left);
        }

        else
        {
            cout << "L: "
                 << "-1"
                 << " , ";
        }

        if (root->right != NULL)
        {
            cout << "R:" << root->right->data << " , ";
            check.push(root->right);
        }

        else
        {
            cout << "R: "
                 << "-1"
                 << " , ";
        }

        cout << endl;
        root = check.front();
    }
}

int numNodes(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return 1 + numNodes(root->left) + numNodes(root->right);
}

int main()
{
    BinaryTreeNode<int> *root = takeInputLevelwise();
    cout << endl;
    printLevelWise(root);
    cout << endl;
    cout << numNodes(root);
    return 0;
}

//1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1