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
int check_balanced(BinaryTreeNode<int>* root)
{
    if(root == NULL) return 0;
    int lh = check_balanced(root->left);
    int rh = check_balanced(root->right);
    if(lh == -1 || rh == -1) return -1;
    if(abs(lh-rh)>1) return -1;
    return 1 + max(lh,rh);
}
bool isBalancedBT(BinaryTreeNode<int>* root) {
    // Write your code here.
    return (check_balanced(root) == -1)?false:true;
}