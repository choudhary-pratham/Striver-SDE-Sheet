int floydWarshall(int n, int m, int src, int dest, vector<vector<int>> &edges) {
    // Write your code here.
    vector<vector<int>>dist(n+1,vector<int>(n+1,1e9));
    for(int i=0;i<m;i++)
    {
        dist[edges[i][0]][edges[i][1]] = edges[i][2];
    }
    for(int k=1;k<=n;k++)
    {
        for(int i = 1;i<=n;i++)
        {
            for(int j = 1;j<=n;j++)
            {
                if(i == j) dist[i][j] = 0;
                else if(dist[i][k] == 1e9 || dist[k][j] == 1e9) continue;
                else dist[i][j] = min(dist[i][j],dist[i][k]+dist[k][j]);
            }
        }
    }
    return dist[src][dest];
}