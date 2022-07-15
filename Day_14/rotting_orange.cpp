#include<queue>
int minTimeToRot(vector<vector<int>>& grid, int n, int m)
{
    // Write your code here.
    queue<pair<int,int>>q;
    int count = 0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(grid[i][j] == 1)
                count++;
            else if(grid[i][j] == 2)
                q.push({i,j});
        }
    }
    int days = 0;
    int dx[] = {-1,1,0,0};
    int dy[] = {0,0,-1,1};
    while(!q.empty())
    {
        int size = q.size();
        for(int i=0;i<size;i++)
        {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            
            for(int dir = 0;dir<4;dir++)
            {
                int newx = x+dx[dir];
                int newy = y+dy[dir];
                if(newx>=0 && newy>=0 && newx<n && newy<m && grid[newx][newy] == 1)
                {
                    grid[newx][newy] = 2;
                    count--;
                    q.push({newx,newy});
                }
            }
        }
        if(!q.empty()) days++;
    }
    if(count == 0) return days;
    return -1;
}