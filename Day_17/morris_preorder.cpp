/*
    Following is Binary Tree Node structure:
    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };
*/
vector<int> getPreOrderTraversal(TreeNode *root)
{
    // Write your code here
    // Write your code here.
    vector<int>preorder;
    if(root == NULL) return preorder;
    TreeNode* cur = root;
    while(cur!=NULL)
    {
        if(cur->left == NULL)
        {
            preorder.push_back(cur->data);
            cur = cur->right;
        }
        else{
            TreeNode* next = cur->left;
            while(next->right && next->right!=cur)
            {
                next = next->right;
            }
            if(next->right == NULL)
            {
                next->right = cur;
                preorder.push_back(cur->data);
                cur = cur->left;
            }
            else{
                next->right = NULL;
                cur = cur->right;
            }
        }
    }
    return preorder;
}