bool dfs(int node,vector<int>&vis,vector<int>&dfsvis,vector<int>adj[])
{
    vis[node] = 1;
    dfsvis[node] = 1;
    for(auto it:adj[node])
    {
        if(!vis[it])
        {
            if(dfs(it,vis,dfsvis,adj) == true) return true;
        }
        else if(dfsvis[it] == 1)
        {
            return true;
        }
    }
    dfsvis[node] = 0;
    return false;
}

void create_adjacency_list(vector<int>adj[],vector<pair<int,int>>&edges,int n)
{
    for(int i=0;i<edges.size();i++)
    {
        adj[edges[i].first].push_back(edges[i].second);
    }
}

int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
  // Write your code here.
    vector<int>vis(n+1,0);
    vector<int>dfsvis(n+1,0);
    vector<int>adj[n+1];
    create_adjacency_list(adj,edges,n);
    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
        {
            if(dfs(i,vis,dfsvis,adj) == true) return 1;
        }
    }
    return 0;
}