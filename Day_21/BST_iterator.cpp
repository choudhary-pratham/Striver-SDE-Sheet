#include<stack>
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

class BSTiterator
{
    public:
    stack<TreeNode<int>*>st;
    void pushAll(TreeNode<int>* root)
    {
        while(root!=NULL)
        {
            st.push(root);
            root = root->left;
        }
    }
    BSTiterator(TreeNode<int> *root)
    {
        // write your code here
        pushAll(root);
    }

    int next()
    {
        // write your code here
        int res = st.top()->data;
        TreeNode<int>* node = st.top();
        st.pop();
        node = node->right;
        pushAll(node);
        return res;
    }

    bool hasNext()
    {
        // write your code here
        return (st.empty() == 0);
    }
};


/*
    Your BSTIterator object will be instantiated and called as such:
    BSTIterator iterator(root);
    while(iterator.hasNext())
    {
       print(iterator.next());
    }
*/