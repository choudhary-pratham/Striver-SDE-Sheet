#include<map>
/************************************************************

Following is the Binary Tree node class
    
template <typename T = int>
class TreeNode
{
public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T val)
    {
        this->data = val;
        left = NULL;
        right = NULL;
    }

    ~TreeNode()
    {
        if (left != NULL)
        {
            delete left;
        }
        if (right != NULL)
        {
            delete right;
        }
    }
};

************************************************************/

vector<int> verticalOrderTraversal(TreeNode<int> *root)
{
    //    Write your code here.
    vector<int>cols;
    if(root == NULL) return cols;
    map<int,map<int,vector<int>>>nodes;
    queue<pair<TreeNode<int>*,pair<int,int>>>q;
    q.push({root,{0,0}});
    while(!q.empty())
    {
        auto front_node = q.front();
        q.pop();
        TreeNode<int>* node = front_node.first;
        int vertical = front_node.second.first;
        int level = front_node.second.second;
        nodes[vertical][level].push_back(node->data);
        if(node->left != NULL)
        {
            q.push({node->left,{vertical-1,level+1}});
        }
        if(node->right != NULL)
        {
            q.push({node->right,{vertical+1,level+1}});
        }
    }
    for(auto p : nodes)
    {
        for(auto q : p.second)
        {
            cols.insert(cols.end(),q.second.begin(),q.second.end());
        }
    }
    return cols;
}