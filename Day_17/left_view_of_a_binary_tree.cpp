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
void recursion(TreeNode<int>* root,int level,vector<int>&leftView)
{
    if(root == NULL) return;
    if(level == leftView.size()) leftView.push_back(root->data);
    recursion(root->left,level+1,leftView);
    recursion(root->right,level+1,leftView);
}
vector<int> getLeftView(TreeNode<int> *root)
{
    //    Write your code here
    vector<int>leftView;
    recursion(root,0,leftView);
    return leftView;
}