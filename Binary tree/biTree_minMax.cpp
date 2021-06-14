#include <iostream>
#include <queue>
#include <climits>
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

pair<int, int> minMax(BinaryTreeNode<int> *root) 
{
    
    pair<int, int> p;
    
    p.first = INT_MIN;
    p.second = INT_MAX;
    
    if(root == NULL)
        return p;
    
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    
    while(!q.empty()){
        
        BinaryTreeNode<int> *front = q.front();
        q.pop();
        
        if(front -> data > p.first){
            p.first = front -> data;
        }
        
        if(front -> data < p.second){
            p.second = front -> data;
        }
        
        if(front -> right){
            q.push(front -> right);
        }
        
        if(front -> left){
            q.push(front -> left);
        }
    }
    
    return p;
}

int main()
{
    BinaryTreeNode<int> *root = takeInput();
    cout << endl;
    print(root);
    cout << endl;
    pair<int, int> Ans = minMax(root);
    cout << "Max : " << Ans.first << "      " << " Min : " << Ans.second << endl;
    delete root;
    return 0;
}