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
    stack<TreeNode*>st;
    TreeNode* cur = root;
    while(cur!=NULL || !st.empty())
    {
        if(cur!=NULL)
        {
            st.push(cur);
            cur = cur->left;
        }
        else
        {
            TreeNode* temp = st.top()->right;
            if(temp == NULL)
            {
                temp = st.top();
                st.pop();
                postorder.push_back(temp->data);
                while(!st.empty() && temp == st.top()->right)
                {
                    temp = st.top();
                    st.pop();
                    postorder.push_back(temp->data);
                }
            }
            else{
                cur = temp;
            }
        }
    }
    return postorder;
}