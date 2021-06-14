#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;
template <typename T>
class TreeNode
{
    public:
    T data;
    vector<TreeNode<int> *> children;

    TreeNode(T data)
    {
        this->data = data;
    }
};

TreeNode<int> *takeInput()
{
    int rootData;
    cout << "Enter root data : ";
    cin >> rootData;
    TreeNode<int> *root = new TreeNode<int>(rootData);

    queue<TreeNode<int> *> pendingNodes;
    pendingNodes.push(root);
    while(pendingNodes.size() != 0)
    {
        TreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        int numChild;
        cout << "Enter number of child nodes of " << front->data << " : ";
        cin >> numChild;
        for(int i = 0; i < numChild; i++)
        {
            int childData;
            cout << "Enter the data of " << i+1 << " th child of " << front->data << " : ";
            cin >> childData;
            TreeNode<int> *child = new TreeNode<int>(childData);
            pendingNodes.push(child);
            front->children.push_back(child);
        }
    }
    return root;
}

void printLevelWise(TreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }

    queue<TreeNode<int> *> pendingQ;
    pendingQ.push(root);
    while(pendingQ.size() != 0)
    {
        TreeNode<int> *front = pendingQ.front();
        cout << front->data << " : ";
        pendingQ.pop();
        for(int i = 0; i < root->children.size(); i++)
        {
            pendingQ.push(root->children[i]);
            if(root->children.size() - 1 != i)
            {
                cout << root->children[i]->data << " , ";
            }
            else
            {
                cout << root->children[i]->data;
            }
        }
        root = pendingQ.front();
        cout << endl;
    }
}

TreeNode<int>* maxSumNode(TreeNode<int> *root){
    
    queue <TreeNode<int>*> q;
    stack <TreeNode<int>*> s;
    
    int large = 0;
    q.push(root);
    
    while(!q.empty()){
        int maxSum = q.front() -> data;
        
        for(int i = 0; i < root -> children.size(); i++){
            q.push(root -> children[i]);
            maxSum += root -> children[i] -> data;
        }
        
        if(maxSum > large){
            s.push(q.front());
            large = maxSum;
        }
        
        q.pop();
        root = q.front();
    }
    return s.top();
}
