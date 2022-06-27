/************************************************************

    Following is the Binary Tree node structure:
    
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
bool isLeaf(TreeNode<int>* node)
{
    return (node->left == NULL && node->right == NULL);
}
void leftBoundary(TreeNode<int>* node,vector<int>&res)
{
    TreeNode<int>* cur = node->left;
    while(cur)
    {
        if(!isLeaf(cur)) res.push_back(cur->data);
        if(cur->left!=NULL) cur = cur->left;
        else cur = cur->right;
    }
}
void leafNodes(TreeNode<int>* node,vector<int>&res)
{
    if(isLeaf(node))
    {
        res.push_back(node->data);
        return;
    }
    if(node->left) leafNodes(node->left,res);
    if(node->right) leafNodes(node->right,res);
}
void rightBoundary(TreeNode<int>* node,vector<int>&res)
{
    TreeNode<int>* cur = node->right;
    int i=0;
    while(cur)
    {
        if(!isLeaf(cur)) {
            res.insert(res.end()-i,cur->data);
            i++;
        }
        if(cur->right!=NULL) cur = cur->right;
        else cur = cur->left;
    }
}
vector<int> traverseBoundary(TreeNode<int>* root){
    // Write your code here.
    vector<int>res;
    if(root == NULL) return res;
    if(!isLeaf(root)) res.push_back(root->data);
    leftBoundary(root,res);
    leafNodes(root,res);
    rightBoundary(root,res);
    return res;
}