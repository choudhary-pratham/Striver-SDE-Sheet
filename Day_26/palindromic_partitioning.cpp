#include<vector>
bool isPalindrome(int i,int j,string& s)
{
	while(i<=j)
	{
		if(s[i]!=s[j]) return false;
		i++;
		j--;
	}
	return true;
}
int palindromePartitioning(string str) {
    // Write your code here
	int n = str.size();
	vector<int>dp(n+1,-1);
	//base case
	dp[n]=0;
	for(int i=n-1;i>=0;i--)
	{
		int mincost = 1e9;
		for(int j=i;j<n;j++)
		{
			if(isPalindrome(i,j,str))
			{
				int cost = 1+dp[j+1];
				mincost = min(mincost,cost);
			}
		}
		dp[i] = mincost;
	}
	return dp[0]-1;
}
