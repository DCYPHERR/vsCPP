#include <iostream>
#include <vector>
#include <queue>
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

TreeNode<int> *takeInputBetter()
{
    int rootData;
    cout << "Enter root data : ";
    cin >> rootData;
    cout << endl;
    TreeNode<int> *root = new TreeNode<int>(rootData);
    queue<TreeNode<int> *> pendingNodes;
    pendingNodes.push(root);
    while (pendingNodes.size() != 0)
    {
        TreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        int numChild;
        cout << "Enter the number of child nodes of " << front->data << " : ";
        cin >> numChild;
        cout << endl;
        for (int i = 0; i < numChild; i++)
        {
            int childData;
            cout << "Enter the data of " << i + 1 << " th node of " << front->data << " : ";
            cin >> childData;
            cout << endl;
            TreeNode<int> *child = new TreeNode<int>(childData);
            pendingNodes.push(child);
            root->children.push_back(child);
        }
    }
    return root;
}

void preOrder(TreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    for (int i = 0; i < root->children.size(); i++)
    {
        preOrder(root->children[i]);
    }
}

int main()
{
    TreeNode<int> *root = takeInputBetter();
    preOrder(root);
    return 0;
}