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

int getMaxWidth(TreeNode<int> *root)
{
    // Write your code here.
    int ans = 0;
    if(root == NULL) return ans;
    queue<TreeNode<int>*>q;
    q.push(root);
    while(!q.empty())
    {
        int size = q.size();
        ans = max(ans,size);
        for(int i=0;i<size;i++)
        {
            TreeNode<int>* cur_node = q.front();
            q.pop();
            if(cur_node->left!=NULL)
            {
                q.push(cur_node->left);
            }
            if(cur_node->right!=NULL)
            {
                q.push(cur_node->right);
            }
        }
    }
    return ans;
}