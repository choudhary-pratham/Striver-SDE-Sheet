void solve(int i,int j,int n,vector<vector<int>>&maze,vector<vector<int>>&grid,vector<vector<int>>&ans,vector<vector<int>>&vis,int di[],int dj[])
{
    if(i == n-1 && j == n-1)
    {
        vector<int>temp;
        for(int x=0;x<n;x++)
        {
            for(int y=0;y<n;y++)
            {
                temp.push_back(grid[x][y]);
            }
        }
        ans.push_back(temp);
        return;
    }
    for(int ind = 0;ind<4;ind++)
    {
        int newi = i+di[ind];
        int newj = j+dj[ind];
        if(newi>=0 && newj>=0 && newi<n && newj<n && vis[newi][newj] == 0 && maze[newi][newj] == 1)
        {
            vis[i][j] = 1;
            grid[i][j] = 1;
            solve(newi,newj,n,maze,grid,ans,vis,di,dj);
            grid[i][j] = 0;
            vis[i][j] = 0;
        }
    }
}

vector<vector<int> > ratInAMaze(vector<vector<int> > &maze, int n){
  // Write your code here.
    vector<vector<int>>ans;
    vector<vector<int>>grid(n,vector<int>(n,0));
    vector<vector<int>>vis(n,vector<int>(n,0));
    int di[] = {1,0,0,-1};
    int dj[] = {0,-1,1,0};
    grid[n-1][n-1]=1;
    if(maze[0][0]==1) solve(0,0,n,maze,grid,ans,vis,di,dj);
    return ans;
}