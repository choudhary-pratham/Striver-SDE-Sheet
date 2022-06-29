#include <map>
/************************************************************

   Following is the TreeNode class structure

   class TreeNode<T>
   {
   public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data)
        {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
   };


 ************************************************************/
TreeNode<int> *buildTree(vector<int> &inorder, int inStart, int inEnd, vector<int> &postorder, int postStart, int postEnd, map<int, int> &inmap)
{
    if (inStart > inEnd || postStart > postEnd)
        return NULL;

    int inroot = inmap[postorder[postEnd]];
    int numsLeft = inroot - inStart;
    TreeNode<int> *root = new TreeNode<int>(postorder[postEnd]);
    root->left = buildTree(inorder, inStart, inroot - 1, postorder, postStart, postStart + numsLeft - 1, inmap);
    root->right = buildTree(inorder, inroot + 1, inEnd, postorder, postStart + numsLeft, postEnd - 1, inmap);

    return root;
}
TreeNode<int> *getTreeFromPostorderAndInorder(vector<int> &postorder, vector<int> &inorder)
{
    // Write your code here.
    if (inorder.size() == 0)
        return NULL;
    map<int, int> inmap;
    for (int i = 0; i < inorder.size(); i++)
    {
        inmap[inorder[i]] = i;
    }
    TreeNode<int> *root = buildTree(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1, inmap);
    return root;
}
