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

TreeNode<int> *nextLargerElement(TreeNode<int> *root, int n)
{

    queue<TreeNode<int> *> q;
    q.push(root);

    TreeNode<int> *res = root;
    int diff = INT_MAX;

    while (!q.empty())
    {

        TreeNode<int> *fr = q.front();
        q.pop();

        if (fr->data - n < diff && fr->data > n)
        {
            res = fr;
            diff = fr->data - n;
        }

        for (int i = 0; i < fr->children.size(); i++)
        {
            q.push(fr->children[i]);
        }
    }
    if (res == root)
        return NULL;
    return res;
}

int main()
{
    TreeNode<int> *root = takeInputLevelWise();
    printLevelWise(root);
    cout << endl;
    cout << nextLargerElement(root, 18);
    //10 3 20 30 40 2 40 50 0 0 0 0
    return 0;
}