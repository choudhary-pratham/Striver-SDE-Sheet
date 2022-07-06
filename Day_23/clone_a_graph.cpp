/***************************************************************************

	Class for graph node is as follows:

	class graphNode
	{
		public:
    		int data;
    	vector<graphNode *> neighbours;
    	graphNode()
    	{
        	data = 0;
        	neighbours = vector<graphNode *>();
    	}

    	graphNode(int val)
    	{
        	data = val;
        	neighbours = vector<graphNode *>();
    	}

    	graphNode(int val, vector<graphNode *> neighbours)
    	{
        	data = val;
        	this->neighbours = neighbours;
    	}
	};

******************************************************************************/
void dfs(graphNode *node,graphNode *copy,vector<graphNode*>&vis)
{
    vis[copy->data] = copy;
    for(auto it:node->neighbours)
    {
        if(vis[it->data] == NULL)
        {
            graphNode *newNode = new graphNode(it->data);
            (copy->neighbours).push_back(newNode);
            dfs(it,newNode,vis);
        }
        else
        {
            (copy->neighbours).push_back(vis[it->data]);
        }
    }
}
graphNode *cloneGraph(graphNode *node)
{
    // Write your code here.
    vector<graphNode*>vis(100001,NULL);
    graphNode* copy = new graphNode(node->data);
    dfs(node,copy,vis);
    return copy;
}