BinaryTreeNode<int> *getTreeFromPostorderAndInorder(int *postOrder, int postLength, int *inOrder, int inLength)
{

    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(postOrder[postLength - 1]);

    if (postLength == 1)
        return root;

    if (postLength == 0)
        return NULL;

    int i = 0;
    while (inOrder[i] != postOrder[postLength - 1])
    {
        i++;
    }

    int left_size = i;
    int right_size = inLength - i - 1;

    BinaryTreeNode<int> *leftSubtree = getTreeFromPostorderAndInorder(postOrder, left_size, inOrder, left_size);
    BinaryTreeNode<int> *rightSubtree = getTreeFromPostorderAndInorder(postOrder + left_size, right_size, inOrder + 1 + left_size, right_size);

    root->left = leftSubtree;
    root->right = rightSubtree;

    return root;
}