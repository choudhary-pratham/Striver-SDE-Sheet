/*************************************************************
 
    Following is the Binary Tree node structure

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
    };

*************************************************************/
bool helper(BinaryTreeNode<int>* root,int lb,int ub)
{
    if(root == NULL) return true;
    if(root->data<lb || root->data>ub) return false;
    return helper(root->left,lb,root->data) && helper(root->right,root->data,ub);
}
bool validateBST(BinaryTreeNode<int> *root) {
    // Write your code here
    if(root == NULL) return true;
    return helper(root,-1e9,1e9);
}