/*************************************************************
 
    Following is the Binary Tree node structure.

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

vector<int> bottomView(BinaryTreeNode<int> * root){

    // Write your code here.
    vector<int>ans;
    if(root == NULL) return ans;
    map<int,BinaryTreeNode<int>*>nodes;
    queue<pair<int,BinaryTreeNode<int>*>>q;
    q.push({0,root});
    while(!q.empty())
    {
        auto p = q.front();
        q.pop();
        BinaryTreeNode<int>*node = p.second;
        int line = p.first;
        if(node->left!=NULL) q.push({line-1,node->left});
        if(node->right!=NULL)q.push({line+1,node->right});
        nodes[line] = node;
    }
    for(auto it:nodes)
    {
        ans.push_back(it.second->data);
    }
    return ans;
}
