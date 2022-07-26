#include<queue>
vector<int> kthSmallLarge(vector<int> &arr, int n, int k)
{
	// Write your code here.
    priority_queue<int>pq1;
    priority_queue<int,vector<int>,greater<int>>pq2;
    for(int i=0;i<n;i++)
    {
        pq1.push(arr[i]);
        pq2.push(arr[i]);
    }
    while(k>1)
    {
        pq1.pop();
        pq2.pop();
        k--;
    }
    vector<int>ans;
    ans.push_back(pq2.top());
    ans.push_back(pq1.top());
    return ans;
}