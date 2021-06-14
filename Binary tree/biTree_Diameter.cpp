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

// int height(BinaryTreeNode<int> *root)
// {
//     if(root == NULL)
//     {
//         return 0;
//     }

//     return 1 + max(height(root->left), height(root->right));
// }

// int diameter(BinaryTreeNode<int> *root)
// {
//     if(root == NULL)
//     {
//         return 0;
//     }

//     int op1 = height(root->left) + height(root->right);
//     int op2 = diameter(root->left);
//     int op3 = diameter(root->right);
//     return max(op1, op2, op3);
     //O(nlogn) <-> O(n^2)
// }

pair<int, int> heightDiameter(BinaryTreeNode<int> *root)
{
    if(root == NULL)
    {
        pair<int, int> p;
        p.first = 0;
        p.second = 0;
        return p;
    }

    pair<int, int> leftAns = heightDiameter(root->left);
    pair<int, int> rightAns = heightDiameter(root->right);
    int ld = leftAns.second;
    int lh = leftAns.first;
    int rd = rightAns.second;
    int rh = rightAns.first;

    int height = 1 + max(lh, rh);
    int diameter = max(lh + rh, max(ld, rd));
    pair<int, int> p;
    p.first = height;
    p.second = diameter;
    return p;
}

int main()
{
    BinaryTreeNode<int> *root = takeInput();
    cout << endl;
    print(root);
    cout << endl;
    pair<int, int> p = heightDiameter(root);
    cout << "Height : " << p.first << "      " << " Diameter : " << p.second;
    delete root;
    return 0;
}

//1 2 3 4 5 -1 -1 6 -1 -1 7 8 -1 -1 9 -1 -1 -1 -1