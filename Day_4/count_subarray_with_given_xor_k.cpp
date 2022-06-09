#include<bits/stdc++.h>
int subarraysXor(vector<int> &arr, int x)
{
    //    Write your code here.
	unordered_map<int,int>mpp;
	int xorr=0;
	int cnt=0;
	for(auto it:arr)
	{
		xorr ^= it;
		if(xorr == x)
		{
			cnt++;
		}
		if(mpp.find(xorr ^ x)!=mpp.end())
		{
			cnt+=mpp[xorr^x];
		}
		mpp[xorr]++;
	}
	return cnt;
}