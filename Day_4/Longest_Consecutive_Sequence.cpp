#include<bits/stdc++.h>
int lengthOfLongestConsecutiveSequence(vector<int> &arr, int n) {
    // Write your code here.
	set<int>hashmap;
	int ans = 1;
	for(auto it:arr)
	{
		hashmap.insert(it);
	}
	for(int i=0;i<n;i++)
	{
		if(!hashmap.count(arr[i]-1))
		{
			int cur_element = arr[i];
			int cnt=1;
			while(hashmap.count(arr[i]+1))
			{
				cnt++;
				arr[i] +=1;
			}
			ans = max(ans,cnt);
		}
	}
	return ans;
}