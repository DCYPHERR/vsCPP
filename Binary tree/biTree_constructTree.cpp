#include <iostream>
#include <queue>
#include <array>
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

int getIndexTarget(int arr[], int targetE)
{
    int size = sizeof(arr) / sizeof(arr[0]);
    int index;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == targetE)
        {
            index = i;
            break;
        }
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

void preOrder(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }

    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }

    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

BinaryTreeNode<int> *constructTreeHelper(int *in, int *pre, int inS, int inE, int preS, int preE)
{
    if (inS > inE)
    {
        return NULL;
    }

    int rootData = pre[preS];
    int rootIndex = -1;
    for (int i = inS; i <= inE; i++)
    {
        if (in[i] == rootData)
        {
            rootIndex = i;
            break;
        }
    }
    int lPreS = preS + 1;
    int lInS = inS;
    int lInE = rootIndex - 1;
    int lPreE = lInE - lInS + lPreS;
    int rPreS = lPreE + 1;
    int rPreE = preE;
    int rInS = rootIndex + 1;
    int rInE = inE;

    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    root->left = constructTreeHelper(in, pre, lInS, lInE, lPreS, lPreE);
    root->right = constructTreeHelper(in, pre, rInS, rInE, rPreS, rPreE);
    return root;
}

BinaryTreeNode<int> *constructTree(int *in, int *pre, int size)
{
    return constructTreeHelper(in, pre, 0, size - 1, 0, size - 1);
}

void printTree(BinaryTreeNode<int> *root)
{
    if (root == NULL)
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
        if (root->left != NULL)
        {
            cout << "L : " << root->left->data << " , ";
            check.push(root->left);
        }
        else
        {
            cout << "L : "
                 << "-1 "
                 << " , ";
        }
        if (root->right != NULL)
        {
            cout << "R : " << root->right->data << " , ";
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

int numNodes(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return 0;

    return 1 + numNodes(root->left) + numNodes(root->right);
}

int main()
{   
    int in[] = {4,2,5,1,8,6,9,3,7};
    int pre[] = {1,2,4,5,3,6,8,9,7};

    BinaryTreeNode<int> *root = constructTree(in, pre, 9);
    printTree(root);
    cout << endl;
    cout << "Num : " << numNodes(root) << endl;
    cout << endl;
    inOrder(root);
    delete root;
    return 0;
}