#include<bits/stdc++.h>
int LongestSubsetWithZeroSum(vector < int > arr) {

  // Write your code here
	int n = arr.size();
	unordered_map<int,int>mpp;
	int maxi=0;
	int s=0;
	for(int i=0;i<n;i++)
	{
		s+=arr[i];
		if(s==0)
		{
			maxi = i+1;
		}
		else
		{
			if(mpp.find(s)!=mpp.end())
			{
				maxi = max(maxi,i-mpp[s]);
			}
			else
			{
				mpp[s] = i;
			}
		}
	}
	return maxi;
}