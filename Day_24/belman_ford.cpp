int bellmonFord(int n, int m, int src, int dest, vector<vector<int>> &edges) {
    // Write your code here.
    vector<int>dist(n+1,1e9);
    dist[src] = 0;
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<edges.size();j++)
        {
            int source = edges[j][0];
            int target = edges[j][1];
            int weight = edges[j][2];
            
            if(dist[source] != 1e9 && dist[source]+weight < dist[target])
            {
                dist[target] = weight + dist[source];
            }
        }
    }
    return dist[dest];
}