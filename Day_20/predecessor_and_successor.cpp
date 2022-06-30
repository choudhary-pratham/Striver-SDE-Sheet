/*************************************************************

    Following is the Binary Tree node structure

    template <typename T>

    class BinaryTreeNode
    {
    public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~BinaryTreeNode() {
            if (left)
            {
                delete left;
            }
            if (right)
            {
                delete right;
            }
        }
    };

*************************************************************/

pair<int,int> predecessorSuccessor(BinaryTreeNode<int>* root, int key)
{
    // Write your code here.
    pair<int,int> ans;
    ans.first = -1;
    ans.second = -1;
    BinaryTreeNode<int>*cur = root;
    while(cur != NULL)
    {
        if(cur->data <= key)
        {
            cur = cur->right;
        }
        else
        {
            ans.second = cur->data;
            cur = cur->left;
        }
    }
    cur = root;
    while(cur != NULL)
    {
        if(cur->data >= key)
        {
            cur = cur->left;
        }
        else
        {
            ans.first = cur->data;
            cur = cur->right;
        }
    }
    return ans;
}
