/************************************************************

    Following is the BinaryTreeNode class structure

    template <typename T>
    class BinaryTreeNode {
       public:
        T val;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
vector<int> getLevelOrder(BinaryTreeNode<int> *root)
{
    //  Write your code here.
    queue<BinaryTreeNode<int>*>q;
    vector<int>level;
    if(root == NULL) return level;
    q.push(root);
    while(!q.empty())
    {
       int size = q.size();
       for(int i=0;i<size;i++)
       {
           BinaryTreeNode<int>* node = q.front();
           q.pop();
           if(node->left != NULL) q.push(node->left);
           if(node->right != NULL) q.push(node->right);
           level.push_back(node->val);
       }
    }
    return level;
}