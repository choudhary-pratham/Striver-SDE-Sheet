#include<vector>
long long  f(int ind,int target,int arr[],vector<vector<long>>&dp)
{
    // base case
    if(ind == 0)
    {
        if(target%arr[0] == 0) return 1;
        else return 0;
    }
    if(dp[ind][target] != -1) return dp[ind][target];
    long long  not_pick = f(ind-1,target,arr,dp);
    long long pick = 0;
    if(arr[ind]<=target) pick = f(ind,target - arr[ind],arr,dp);
    
    return dp[ind][target] = not_pick+pick;
}

long countWaysToMakeChange(int *arr, int n, int value)
{
    //Write your code here
   	vector<long>prev(value+1,0),cur(value+1,0);
    for(int i=0;i<=value;i++)
    {
        if(i%arr[0] == 0)
        	prev[i] = 1; 
    }
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<=value;j++)
        {
            long long  not_pick = prev[j];
            long long pick = 0;
            if(arr[i]<=j) pick = cur[j - arr[i]];

            cur[j] = not_pick+pick;
        }
        prev = cur;
    }
    return prev[value];
}