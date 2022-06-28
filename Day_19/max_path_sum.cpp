/************************************************************

    Following is the Tree node structure
	
	template <typename T>
    class TreeNode 
    {
        public : 
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) 
        {
            this -> val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
int find_maximum(TreeNode<int>*root,long long int &maxi,long long int&count)
{
    if(root == NULL) return 0;
    if(root->left == NULL && root->right == NULL) count++;
    long long int lh = max(0,find_maximum(root->left,maxi,count));
    long long int  rh = max(0,find_maximum(root->right,maxi,count));
    maxi = max(maxi,root->val+lh+rh);
    return root->val + max(lh,rh);
}
long long int findMaxSumPath(TreeNode<int> *root)
{
    // Write your code here.
    long long int maxi = -1e9;
    long long int count = 0;
    if(root == NULL) return -1;
    find_maximum(root,maxi,count);
    return (count == 1)?-1:maxi;
}