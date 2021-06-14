#include <iostream>
#include <vector>
#include <queue>
using namespace std;
template <typename T>
class TreeNode 
{
    public:
    T data;
    vector<TreeNode<T> *> children;

    TreeNode (T data)
    {
        this->data = data;
    }
};

// TreeNode<int>* takeInput()
// {
//     int rootData;
//     cout << "Enter Data : ";
//     cin >> rootData;
//     TreeNode<int>* root = new TreeNode<int>(rootData);
    
//     int n;
//     cout << "Enter number of children of " << rootData << " :";
//     cin >> n;
    
//     for(int i = 0; i < n; ++i)
//     {
//         TreeNode<int>* child = takeInput();
//         root->children.push_back(child);
//     }
//     return root;
// }

TreeNode<int>* takeInputlevelWise()
{
    int rootData;
    cout << "Enter root data" << endl;
    cin >> rootData;
    TreeNode<int>* root = new TreeNode<int>(rootData);

    queue<TreeNode<int> *> pendingNodes;
    pendingNodes.push(root);
    while(pendingNodes.size() != 0)
    {
        TreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        cout << "Enter number of children of  " << front->data << " :";
        int numChild;
        cin >> numChild;
        for(int i = 0; i<numChild; ++i)
        {   
            int childData;
            cout << "Enter " << i+1 << " th child of " << front->data << endl;
            cin >> childData;
            TreeNode<int>* child = new TreeNode<int>(childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }
    return root;
}

// void print(TreeNode<int>* root)
// {
//     if(root == NULL)
//     {
//         return;
//     }

//     cout << root->data << " : ";
//     for(int i = 0; i < root->children.size(); ++i)
//     {
//         cout << root->children[i]->data << " , ";
//     }
//     cout << endl;
//     for(int i = 0; i < root->children.size(); ++i)
//     {
//         print(root->children[i]);
//     }
// }

void printLevelWise(TreeNode<int>* root)
{
    if(root == NULL)
    {
        return;
    }
    queue<TreeNode<int> *> pendingQ;
    pendingQ.push(root);
    while(pendingQ.size() != 0)
    {
        TreeNode<int> *front = pendingQ.front();
        cout << front -> data << ":";
        pendingQ.pop();
        for(int i = 0; i<root->children.size(); i++)
        {
            pendingQ.push(root->children[i]);

            if(root->children.size() - 1 != i)
            {
                cout << root->children[i]->data << ",";
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

int main()
{   
    TreeNode<int>* root = takeInputlevelWise();
    printLevelWise(root);
    return 0;
}