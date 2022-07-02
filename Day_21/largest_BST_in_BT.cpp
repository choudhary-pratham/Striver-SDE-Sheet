#include<limits.h>
/************************************************************

    Following is the Binary Tree node structure
    
    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/
class NodeValue{
    public:
    int maxSize,minNode,maxNode;
    NodeValue(int maxSize,int minNode,int maxNode)
    {
        this->maxSize = maxSize;
        this->minNode = minNode;
        this->maxNode = maxNode;
    }
};
NodeValue sizeOfLargestBST(TreeNode<int>* root)
{
    if(root == NULL)
    {
        return NodeValue(0,INT_MAX,INT_MIN);
    }
    
    auto left = sizeOfLargestBST(root->left);
    auto right = sizeOfLargestBST(root->right);
    
    if(left.maxNode<root->data && root->data<right.minNode)
    {
        return NodeValue(1+left.maxSize+right.maxSize,min(root->data,left.minNode),max(root->data,right.maxNode));
    }
    return NodeValue(max(left.maxSize,right.maxSize),INT_MIN,INT_MAX);
}
int largestBST(TreeNode<int>* root) 
{
    // Write your code here.
    return sizeOfLargestBST(root).maxSize;
}
