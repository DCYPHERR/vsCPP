// #include <iostream>
// #include <vector>
// using namespace std;

// int main()
// {
//     vector<int> v;
//     // vector<int> *v = new vector<int>();
//     v.push_back(10);
//     v.push_back(20);
//     v.push_back(30);

//     v[1] = 100;

//     cout << v[0] << endl;
//     cout << v[1] << endl;
//     cout << v[2] << endl;

//     return 0;
// }



#include <iostream>
#include <vector>
using namespace std;
template <typename T> 
class TreeNode
{   
    public:
    T data;
    vector<TreeNode<T>*> children;

    TreeNode(T data)
    {
        this->data = data; 
    }
};

void print(TreeNode<int>* root)
{   
    if(root == NULL)
    {
        return;
    }
    cout << root->data << " : ";
    for(int i = 0; i<root->children.size(); i++)
    {
        cout << root->children[i]->data << " , ";
    }
    cout << endl;
    for(int i = 0; i < root->children.size(); i++)
    {
        print(root->children[i]);
    }
}

int main()
{
    TreeNode<int>* root = new TreeNode<int>(1);
    TreeNode<int>* node1 = new TreeNode<int>(2);
    TreeNode<int>* node2 = new TreeNode<int>(3);
    // TreeNode<int>* subnode1 = new TreeNode<int>(69);
    root->children.push_back(node1);
    root->children.push_back(node2);
    // node1->children.push_back(subnode1);
    print(root);
    //TODO delete the tree
    return 0;
}