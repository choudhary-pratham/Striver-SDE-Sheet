#include<bits/stdc++.h>
string fourSum(vector<int> arr, int target, int n) {
    // Write your code here.
	sort(arr.begin(),arr.end());
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			int target_2 = target-(arr[i]+arr[j]);
			int start = j+1;
			int end = n-1;
			while(start<end)
			{
				if(arr[start]+arr[end] < target_2) start++;
				else if(arr[start]+arr[end] > target_2) end--;
				else
				{
					return "Yes";
				}
			}
			while(j+1<n && arr[j+1] == arr[j])++j;
		}
		while(i+1<n && arr[i+1] == arr[i])++i;
	}
	return "No";
}
