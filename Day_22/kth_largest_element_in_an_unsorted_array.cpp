int kthLargest(vector<int>& arr, int size, int K)
{
	// Write your code here.
    priority_queue<int>pq;
    for(int i=0;i<size;i++)
    {
        pq.push(arr[i]);
    }
    while(K > 1)
    {
        pq.pop();
        K--;
    } 
    return pq.top();
}