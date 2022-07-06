bool dfs_bipartite(int nodei,vector<int>&color,vector<vector<int>> &edges)
{
    if(color[nodei] == -1) color[nodei] = 0;
    for(int j=0;j<edges.size();j++)
    {
        if(edges[nodei][j] == 1)
        {
            if(color[j] == -1)
            {
                color[j] = !color[nodei];
                if(dfs_bipartite(j,color,edges) == false) return false;
            }
            else if(color[nodei] == color[j])
            {
                return false;
            }
        }
    }
    return true;
}
bool isGraphBirpatite(vector<vector<int>> &edges) {
	// Write your code here.
    int n = edges.size();
    vector<int>color(n,-1);
    for(int i=0;i<n;i++)
    {
        if(color[i] == -1)
        {
            if(dfs_bipartite(i,color,edges) == false) return false;
        }
    }
    return true;
}