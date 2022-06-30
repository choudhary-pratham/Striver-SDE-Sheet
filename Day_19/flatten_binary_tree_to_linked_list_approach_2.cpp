#include<stack>
/************************************************************

    Following is the TreeNode class structure.

    template <typename T>
    class TreeNode {
        public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

TreeNode<int> *flattenBinaryTree(TreeNode<int> *root)
{
    // Write your code here.
    TreeNode<int>*cur = root;
    while(cur!=NULL)
    {
        if(cur->left != NULL)
        {
            TreeNode<int>*next = cur->left;
            while(next->right!=NULL)
            {
                next = next->right;
            }
            next->right = cur->right;
            cur->right = cur->left;
        }
        cur = cur->right;
    }
    return root;
}