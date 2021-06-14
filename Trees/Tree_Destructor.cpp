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

    TreeNode(T data)
    {
        this->data = data;
    }

    ~TreeNode
    {
        for (int i = 0; i < children.size(); i++)
            delete children[i];
    }
};


TreeNode<int> *takeInputLevelWise()
{
    int rootData;
    cout << "Enter root data : ";
    cin >> rootData;
    TreeNode<int> *root = new TreeNode<int>(rootData);
    queue<TreeNode<int> *> pendingNodes;
    pendingNodes.push(root);
    while (pendingNodes.size() != 0)
    {
        TreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        int numChild;
        cout << "Enter Number of child nodes of " << front->data << " : ";
        cin >> numChild;
        for (int i = 0; i < numChild; i++)
        {
            cout << "Enter data of " << i + 1 << " th child of " << front->data << " : ";
            int childData;
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
    while (pendingQ.size() != 0)
    {
        TreeNode<int> *front = pendingQ.front();
        cout << front->data << " : ";
        pendingQ.pop();
        for (int i = 0; i < root->children.size(); i++)
        {
            pendingQ.push(root->children[i]);
            if (root->children.size() - 1 != i)
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

// void deleteTree(TreeNode<int> *root)
// {
//     for (int i = 0; i < root->children.size(); i++)
//     {
//         deleteTree(root->children[i]);
//     }
//     delete root;
// }

int main()
{
    TreeNode<int> *root = takeInputLevelWise();
    printLevelWise(root);
    cout << endl;
    // deleteTree(root);
    delete root; //Uses modified destructor to do the same job as the function
    return 0;
}