#include<bits/stdc++.h>
struct activity
{
	int start;
	int end;
	int pos;
};
bool comp(struct activity a1,activity a2)
{
	if(a1.end<a2.end) return true;
	else if(a1.end>a2.end) return false;
	else if(a1.pos<a2.pos) return true;
	return false;
}
int maximumActivities(vector<int> &start, vector<int> &finish) {
    // Write your code here.
	int n = start.size();
	struct activity a[n];
	for(int i=0;i<n;i++)
	{
		a[i].start = start[i];
		a[i].end = finish[i];
		a[i].pos = i+1;
	}
	
	sort(a,a+n,comp);
	
	int limit = a[0].end;
	int count=1;
	for(int i=1;i<n;i++)
	{
		if(a[i].start>=limit)
		{
			limit = a[i].end;
			count++;
		}
	}
	return count;
}