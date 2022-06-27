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
int findDiameter(TreeNode<int>* root,int &maxi)
{
    if(root == NULL) return 0;
    int lh = findDiameter(root->left,maxi);
    int rh = findDiameter(root->right,maxi);
    maxi = max(maxi,lh+rh);
    return 1+max(lh,rh);
}
int diameterOfBinaryTree(TreeNode<int> *root)
{
	// Write Your Code Here.
    int maxi = 0;
    if(root == NULL) return maxi;
    findDiameter(root,maxi);
    return maxi;
}
