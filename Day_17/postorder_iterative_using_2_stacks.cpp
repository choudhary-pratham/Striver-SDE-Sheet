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
vector<int> getPostOrderTraversal(TreeNode *root)
{
    // Write your code here.
    vector<int>postorder;
    if(root == NULL) return postorder;
    stack<TreeNode*>st1,st2;
    st1.push(root);
    while(!st1.empty())
    {
        TreeNode* node = st1.top();
        st1.pop();
        st2.push(node);
        if(node->left != NULL) st1.push(node->left);
        if(node->right != NULL) st1.push(node->right);
    }
    while(!st2.empty())
    {
        postorder.push_back(st2.top()->data);
        st2.pop();
    }
    return postorder;
}