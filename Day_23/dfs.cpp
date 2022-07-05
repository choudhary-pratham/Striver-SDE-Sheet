void create_adjacency_list(vector<int>adj[],vector<vector<int>>&edges,int n)
{
    for(int i=0;i<n;i++)
    {
        adj[edges[i][0]].push_back(edges[i][1]);
        adj[edges[i][1]].push_back(edges[i][0]);
    }
}
void dfs(int i,vector<int>adj[],vector<int>&nodes,vector<int>&vis)
{
    nodes.push_back(i);
    vis[i] = 1;
    for(auto it:adj[i])
    {
        if(!vis[it])
        {
            dfs(it,adj,nodes,vis);
        }
    }
}

vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    // Write your code here
    vector<vector<int>>ans;
    vector<int>nodes;
    vector<int>vis(V,0);
    vector<int>adj[V];
    create_adjacency_list(adj,edges,E);
    for(int i=0;i<V;i++)
    {
        if(!vis[i])
        {
            dfs(i,adj,nodes,vis);
            ans.push_back(nodes);
            nodes.clear();
        }
    }
    return ans;
}