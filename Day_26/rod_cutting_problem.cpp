int f(int ind,int target,vector<int>&price,vector<vector<int>>&dp)
{
    //base case
    if(ind == 0)
    {
        return target*price[0];
    }
    if(dp[ind][target] != -1) return dp[ind][target];
    int not_pick = f(ind-1,target,price,dp);
    int pick = -1e8;
    if(target>=(ind+1)) pick = price[ind] + f(ind,target - (ind+1),price,dp);
    
    return dp[ind][target] = max(pick,not_pick);
}
int cutRod(vector<int> &price, int n)
{
    vector<int>prev(n+1,0);
    //base case
    for(int i=0;i<=n;i++)
    {
        prev[i] = i*price[0];
    }
    
    for(int ind=1;ind<n;ind++)
    {
        for(int target = 0;target<=n;target++)
        {
            int not_pick = prev[target];
            int pick = -1e8;
            if(target>=(ind+1)) pick = price[ind] + prev[target - (ind+1)];

           	prev[target] = max(pick,not_pick);
        }
    }
    return prev[n];
}
