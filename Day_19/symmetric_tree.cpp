/*****************************************************

    Following is the Binary Tree node structure:
    
    class BinaryTreeNode {
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
            if(left) 
                delete left;
            if(right) 
                delete right;
        }
    };

******************************************************/

bool check_for_symmetric(BinaryTreeNode<int>* node1,BinaryTreeNode<int>*node2)
{
    if(node1 == NULL || node2 == NULL) return node1 == node2;
    
    return node1->data == node2->data && check_for_symmetric(node1->left,node2->right) && check_for_symmetric(node1->right,node2->left);
}
bool isSymmetric(BinaryTreeNode<int>* root)
{
    // Write your code here. 
    if(root == NULL) return true;
    return check_for_symmetric(root->left,root->right);
}