#include<stack>
/**********************************************************

    Following is the Binary Tree Node structure:

    template <typename T>
    class BinaryTreeNode {
        public: 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }

        ~BinaryTreeNode() {
            if (left)
                delete left;
            if (right)
                delete right;
        }
    };
***********************************************************/
class BSTiterator
{
    private:
    stack<BinaryTreeNode<int>*>myStack;
    bool reverse = true;
    public:
    BSTiterator(BinaryTreeNode<int>*root,bool isreverse)
    {
        reverse = isreverse;
        pushAll(root);
    }
    void pushAll(BinaryTreeNode<int>*root)
    {
        while(root!=NULL)
        {
            myStack.push(root);
            if(reverse == true) root = root->right;
            else root = root->left;
        }
    }
    int next()
    {
        BinaryTreeNode<int>* node = myStack.top();
        myStack.pop();
        if(reverse == true) pushAll(node->left);
        else pushAll(node->right);
        return node->data;
    }
    bool hasnext()
    {
        return !myStack.empty();
    }
};
bool pairSumBst(BinaryTreeNode<int> *root, int k)
{
    // Write your code here
    BSTiterator l(root,false);
    BSTiterator r(root,true);
    int i = l.next();
    int j = r.next();
    while(i<j)
    {
        if(i+j == k) return true;
        else if(i+j<k) i = l.next();
        else j = r.next();
    }
    return false;
}