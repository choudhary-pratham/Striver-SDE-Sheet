#include<queue>
vector<int> findMedian(vector<int> &arr, int n){
	// Write your code here 
    priority_queue<int>q1;
    priority_queue<int,vector<int>,greater<int>>q2;
    vector<int>res;
    for(int i=0;i<n;i++)
    {
        if(q1.empty() || q1.top() > arr[i])
        {
            q1.push(arr[i]);
        }
        else{
            q2.push(arr[i]);
        }
        if(q1.size() > q2.size()+1)
        {
            q2.push(q1.top());
            q1.pop();
        }
        else if(q2.size() > q1.size()+1)
        {
            q1.push(q2.top());
            q2.pop();
        }
        int val = 0;
        if(q1.size() == q2.size())
        {
            val = (q1.top()+q2.top())/2;
        }
        else if(q1.size() > q2.size())
        {
            val = q1.top();
        }
        else{
            val = q2.top();
        }
        res.push_back(val);
    }
    return res;
}
