#include<stack>
void topologicalSortDfs(int node,vector<int>adj[],stack<int>&st,vector<int>&vis)
{
    vis[node] = 1;
    for(auto it:adj[node])
    {
        if(!vis[it])
        {
            topologicalSortDfs(it,adj,st,vis);
        }
    }
    st.push(node);
}
void findTranspose(int n,vector<int>transpose[],vector<int>adj[],vector<int>&vis)
{
    for(int i=0;i<n;i++)
    {
        vis[i] = 0;
        for(auto it:adj[i])
        {
            transpose[it].push_back(i);
        }
    }
}

void dfs(int node,vector<int>transpose[],vector<int>&visited,vector<int>&scc)
{
    visited[node] = 1;
    scc.push_back(node);
    for(auto it:transpose[node])
    {
        if(!visited[it])
        {
            dfs(it,transpose,visited,scc);
        }
    }
}
vector<vector<int>> stronglyConnectedComponents(int n, vector<vector<int>> &edges)
{
    vector<int>adj[n];
    for(int i=0;i<edges.size();i++)
    {
        adj[edges[i][0]].push_back(edges[i][1]);
    }
    //step 1-> Topological sorting
    stack<int>st;
    vector<int>vis(n,0);
    for(int i=0;i<n;i++)
    {
        if(!vis[i])
        {
            topologicalSortDfs(i,adj,st,vis);
        }
    }
    //step 2->find the tranpose of the adjacency list
    vector<int>transpose[n];
    findTranspose(n,transpose,adj,vis);
    //step 3->dfs traversal in the order of their finishing time
    vector<vector<int>>ans;
    while(!st.empty())
    {
        int node = st.top();
        st.pop();
        
        if(!vis[node]){
            vector<int>scc;
            dfs(node,transpose,vis,scc);
            ans.push_back(scc);
        }
    }
    return ans;
}