#include<algorithm>
int maxIncreasingDumbbellsSum(vector<int> &arr, int n)
{
	// Write your code here
    vector<int>dp(n+1,0);
    int ans = 0;
    for(int i = 0;i<n;i++)
    {
        int sum = arr[i];
        for(int j = 0;j<i;j++)
        {
            if(arr[j]<arr[i])
            {
                sum = max(sum,(arr[i] + dp[j]));
            }
        }
        dp[i] = sum;
        ans = max(ans,dp[i]);
    }
    return ans;
}