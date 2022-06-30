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
    stack<TreeNode<int>*>st;
    st.push(root);
    while(!st.empty())
    {
        TreeNode<int>* cur = st.top();
        st.pop();
        if(cur->right!=NULL)
        {
            st.push(cur->right);
        }
        if(cur->left!=NULL)
        {
            st.push(cur->left);
        }
        if(!st.empty())
        {
            cur->right = st.top();
        }
        cur->left = NULL;
    }
    return root;
}