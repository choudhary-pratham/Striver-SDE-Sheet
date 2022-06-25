#include<map>
/************************************************************

    Following is the TreeNode class structure:

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

vector<int> getTopView(TreeNode<int> *root) {
    // Write your code here.
    vector<int>ans;
    if(root == NULL) return ans;
    map<int,TreeNode<int>*>nodes;
    queue<pair<int,TreeNode<int>*>>q;
    q.push({0,root});
    while(!q.empty())
    {
        auto p = q.front();
        q.pop();
        TreeNode<int>*node = p.second;
        int line = p.first;
        if(node->left!=NULL) q.push({line-1,node->left});
        if(node->right!=NULL) q.push({line+1,node->right});
        if(nodes[line] == NULL) nodes[line] = node;
    }
    for(auto it:nodes)
    {
        ans.push_back(it.second->val);
    }
    return ans;
}