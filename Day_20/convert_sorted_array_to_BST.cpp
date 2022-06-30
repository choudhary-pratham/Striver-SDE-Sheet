/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;
        
        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
TreeNode<int>* buildTree(vector<int>&arr,int start,int end)
{
    if(start>end) return NULL;
    int mid = (start+end)/2;
    TreeNode<int>* root = new TreeNode<int>(arr[mid]);
    root->left = buildTree(arr,start,mid-1);
    root->right = buildTree(arr,mid+1,end);
    return root;
}
TreeNode<int>* sortedArrToBST(vector<int> &arr, int n)
{
    // Write your code here
    TreeNode<int>* res =  buildTree(arr,0,n-1);
    return res;
}