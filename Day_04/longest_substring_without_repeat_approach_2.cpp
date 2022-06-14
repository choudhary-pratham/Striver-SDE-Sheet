#include<bits/stdc++.h>
int uniqueSubstrings(string input)
{
    //Write your code here
	int n=input.size();
	int l=0,r=0,len=0;
	map<char,int>mpp;
	while(r<n)
	{
		if(mpp.find(input[r])!=mpp.end()) l = max(l,mpp[input[r]]+1);
		mpp[input[r]] = r;
		len = max(len,r-l+1);
		r++;
	}
	return len;
}