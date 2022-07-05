#include<stack>
void dfs(int node,vector<int>&vis,vector<int>adj[],stack<int>&st)
{
    vis[node] = 1;
    for(auto it:adj[node])
    {
        if(!vis[it])
        {
            dfs(it,vis,adj,st);
        }
    }
    st.push(node);
}

void create_adjacency_list(vector<int>adj[],vector<vector<int>>&edges)
{
    for(int i=0;i<edges.size();i++)
    {
        adj[edges[i][0]].push_back(edges[i][1]);
    }
}

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    // Write your code here
    vector<int>ans;
    vector<int>vis(v,0);
    stack<int>st;
    vector<int>adj[v];
    create_adjacency_list(adj,edges);
    for(int i=0;i<v;i++)
    {
        if(!vis[i])
        {
            dfs(i,vis,adj,st);
        }
    }
    while(!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
}