#include<vector>
int cutLogs(int K, int N)
{
    // Write your code here.
    vector<int>prev(N+1,0),cur(N+1,0);
    prev[0] = 0;
    prev[1] = 1;
    for(int i = 0;i<=N;i++)
    {
        prev[i] = i;
    }
    
    for(int k = 2;k<=K;k++)
    {
        cur[0]=0;
        cur[1]=1;
        for(int n = 2;n<=N;n++)
        {
            int mini = 1e9;
            int l = 1,h=n;
            while(l<=h)
            {
                int mid = (l+h)>>1;
                int temp = 1 + max(prev[mid-1],cur[n-mid]);
                if(prev[mid-1]>cur[n-mid]) h = mid-1;
                else l = mid+1;
                mini = min(mini,temp);
            }
            cur[n] = mini;
        }
        prev = cur;
    }
    return prev[N];
}
