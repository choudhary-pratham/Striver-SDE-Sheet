#include<queue>
#include<sstream>
/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

string serializeTree(TreeNode<int> *root)
{
 //    Write your code here for serializing the tree
    if(root == NULL) return "";
    string s = "";
    queue<TreeNode<int>*>q;
    q.push(root);
    while(!q.empty())
    {
        TreeNode<int>*node = q.front();
        q.pop();
        if(node == NULL) s+="#,";
        else
        {
            s += (to_string(node->data)+',');   
        }
        if(node!=NULL)
        {
            q.push(node->left);
            q.push(node->right);
        }
    }
    return s;
}

TreeNode<int>* deserializeTree(string &serialized)
{
 //    Write your code here for deserializing the tree
    if(serialized.size() == 0) return NULL;
    stringstream s(serialized);
    string str;
    getline(s,str,',');
    TreeNode<int>*root = new TreeNode<int>(stoi(str));
    queue<TreeNode<int>*>q;
    q.push(root);
    while(!q.empty())
    {
        TreeNode<int>* node = q.front();
        q.pop();
        getline(s,str,',');
        if(str == "#")
        {
            node->left = NULL;
        }
        else{
            TreeNode<int>*newNode = new TreeNode<int>(stoi(str));
            node->left = newNode;
            q.push(newNode);
        }
        getline(s,str,',');
        if(str == "#")
        {
            node->right = NULL;
        }
        else{
            TreeNode<int>*newNode = new TreeNode<int>(stoi(str));
            node->right = newNode;
            q.push(newNode);
        }
    }
    return root;
}



