#include<queue>
bool bfs_bipartite(int nodei,vector<int>&color,vector<vector<int>> &edges)
{
    queue<int>q;
    q.push(nodei);
    color[nodei] = 0;
    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        for(int j = 0;j<edges.size();j++)
        {
            if(edges[node][j] == 1)
            {
                if(color[j] == -1)
                {
                    color[j] = !color[node];
                    q.push(j);
                }
                else if(color[j] == color[node])
                {
                    return false;
                }
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
            if(bfs_bipartite(i,color,edges) == false) return false;
        }
    }
    return true;
}