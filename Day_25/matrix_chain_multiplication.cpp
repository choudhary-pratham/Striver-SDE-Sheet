int matrixMultiplication(vector<int> &arr, int N)
{
    vector<vector<int>>dp(N,vector<int>(N,0));
    //base case
    for(int i=1;i<=N-1;i++)
    {
        dp[i][i] = 0;
    }
    for(int i=N-1;i>=1;i--)
    {
        for(int j=i+1;j<=N-1;j++)
        {
            int mini = 1e9;
            for(int k=i;k<=j-1;k++)
            {
                int steps = arr[i-1]*arr[k]*arr[j]+dp[i][k]+dp[k+1][j];
                mini = min(steps,mini);
            }
            dp[i][j] = mini;
        }
    }
    return dp[1][N-1];
}