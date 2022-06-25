/*   
    template <typename T = int>
	class TreeNode
	{
		public:
		T data;
		TreeNode<T> *left;
		TreeNode<T> *right;

		TreeNode(T data)
		{
			this->data = data;
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
*/

bool findPath(TreeNode<int>* root,int x,vector<int>&path)
{
    if(root == NULL) return false;
    path.push_back(root->data);
    if(root->data == x) {
        return true;
    }
    if(findPath(root->left,x,path) || findPath(root->right,x,path)){
        return true;
    }
    path.pop_back();
    return false;
}
vector<int> pathInATree(TreeNode<int> *root, int x)
{
    // Write your code here.
    vector<int>path;
    if(root == NULL) return path;
    findPath(root,x,path);
    return path;
}
