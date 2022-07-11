bool f(int i,int target,vector<int>&arr,vector<vector<int>>&dp)
{
    //base case
    if(target == 0) return true;
    if(i==0) 
    {
        if(target == arr[0]) return true;
        else return false;
    }
    if(dp[i][target]!=-1) return dp[i][target];
    bool take = false;
    if(target>=arr[i])  take = f(i-1,target-arr[i],arr,dp);
    bool not_take =  f(i-1,target,arr,dp);
    return dp[i][target] = take|not_take;
}


bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.
    vector<bool>prev(k+1,0),cur(k+1,0);
    prev[0] = true;
    prev[arr[0]] = true;
    for(int i=1;i<n;i++)
    {
        cur[0] = true;
        for(int target = 1;target<=k;target++)
        {
            bool take = false;
            if(target>=arr[i])  take = prev[target-arr[i]];
            bool not_take =  prev[target];
            cur[target] = take|not_take;
        }
        prev = cur;
    }
    return prev[k];
}