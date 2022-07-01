/************************************************************

    Following is the TreeNode class structure

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
void helper(TreeNode<int>*root,int &k,int &ans)
{
    if(root == NULL) return;
    helper(root->left,k,ans);
    k--;
    if(k == 0) 
    {
        ans = root->data;
        return;
    }
    helper(root->right,k,ans);
}
int kthSmallest(TreeNode<int> *root, int k)
{
	//	Write the code here.
    int ans=0;
    helper(root,k,ans);
    return ans;
}