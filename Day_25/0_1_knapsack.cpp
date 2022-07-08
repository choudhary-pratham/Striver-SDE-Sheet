int maxProfit(vector<int> &values, vector<int> &weights, int n, int W)
{
	// Write your code here
    vector<int>prev(W+1,0);
    for(int i = weights[0] ; i<=W;i++)
    {
        prev[i] = values[0];
    }
    for(int ind=1;ind<n;ind++)
    {
        for(int w = W;w>=0;w--)
        {
            int not_pick = prev[w];
            int pick = -1e9;
            if(w>=weights[ind])
            {
                pick = values[ind]+prev[w-weights[ind]];
            }
            prev[w] = max(pick,not_pick);
        }
    }
    return prev[W];
}